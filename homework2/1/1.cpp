#include <iostream>
#include <array>
#include <cstddef>   
#include <algorithm> 

constexpr std::size_t alignment_for_size(int size) {
    if (size <= 1) return 1;
    if (size <= 2) return 2;
    if (size <= 4) return 4;
    return 8;
}

constexpr std::size_t align_up(std::size_t offset, std::size_t align) {
    return (offset + (align - 1)) & ~(align - 1);
}
template<std::size_t N>
void print_member_offsets(const std::array<int, N>& arr) {
    std::size_t offset = 0;
    std::size_t struct_align = 1;

    std::cout << "Member | Size | Align | Address(offset)\n";
    std::cout << "--------------------------------------\n";

    for (std::size_t i = 0; i < N; ++i) {
        int s = arr[i];
        if (s <= 0) continue;

        std::size_t align = alignment_for_size(s);
        struct_align = std::max(struct_align, align);

        offset = align_up(offset, align);

        std::cout << "  M" << i << "     |  "
                  << s << "   |  "
                  << align << "    |  "
                  << offset << "\n";

        offset += s;
    }

    std::size_t total = align_up(offset, struct_align);
    std::cout << "--------------------------------------\n";
    std::cout << "Total class size: " << total << "\n";
}
template<std::size_t N>
std::size_t class_size_from_array(const std::array<int, N>& arr) {
    std::size_t offset = 0;
    std::size_t struct_align = 1;

    for (int s : arr) {
        if (s <= 0) continue;
        std::size_t sz = static_cast<std::size_t>(s);
        std::size_t a = alignment_for_size(s);

        struct_align = std::max(struct_align, a);
        offset = align_up(offset, a);
        offset += sz;
    }

    return align_up(offset, struct_align);
}

int main() {
    std::array<int, 3> a1 = {1, 4, 1};     
    std::array<int, 4> a2 = {1, 1, 1, 1};  
    std::array<int, 3> a3 = {8, 1, 4};     

    std::cout << "Size {1,4,1}  -> " << class_size_from_array(a1) << "\n";
    std::cout << "Size {1,1,1,1}-> " << class_size_from_array(a2) << "\n";
    std::cout << "Size {8,1,4}  -> " << class_size_from_array(a3) << "\n";

    std::cout << "Example 1 ( {1,4,1} )\n";
    print_member_offsets(a1);

    std::cout << "\nExample 2 ( {1, 1, 1, 1} )\n";
    print_member_offsets(a2);
}
