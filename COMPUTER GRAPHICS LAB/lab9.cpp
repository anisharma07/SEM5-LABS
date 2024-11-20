#include <iostream>
#include <iomanip> // For formatting the output (hex and setfill)

std::string rgb_to_hex(int r, int g, int b)
{
    // Ensure that the RGB values are within the 0-255 range
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        return "Invalid RGB values. Each value should be between 0 and 255.";
    }

    std::stringstream ss;
    // Convert RGB to Hex format and pad with zeros if needed
    ss << "#" << std::hex << std::setfill('0') << std::setw(2) << r
       << std::setw(2) << g
       << std::setw(2) << b;

    return ss.str();
}

int main()
{
    int r, g, b;
    // Get RGB values from user
    std::cout << "Enter Red (0-255): ";
    std::cin >> r;
    std::cout << "Enter Green (0-255): ";
    std::cin >> g;
    std::cout << "Enter Blue (0-255): ";
    std::cin >> b;

    // Convert RGB to Hex
    std::string hex_color = rgb_to_hex(r, g, b);

    // Output the result
    std::cout << "RGB(" << r << ", " << g << ", " << b << ") -> Hex: " << hex_color << std::endl;

    return 0;
}
