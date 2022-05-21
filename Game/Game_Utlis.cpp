#include"Game_Utlis.h"
bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    if (object1.x + object1.w >= object2.x && object2.x + object2.w >= object1.x
        && object1.y + object1.h >= object2.y && object2.y + object2.h >= object1.y)
    {
        return true;
    }
    return false;
} 
// apply for score
string convert_to_string(int number)
{
    stringstream ss;
    ss << setw(5) << setfill(' ') << number;
    string val_score;
    ss >> val_score;
    return val_score;
}
// apply for health
string convert_to_String(int health)
{
    stringstream ss;
    ss << setw(4) << setfill('0') << health;
    string val_score;
    ss >> val_score;
    val_score = val_score ;
    return val_score;
}

int get_from_file (const char* path)
{
    int x;
    std::ifstream file(path);
    string value;
    file >> value;
    x = std::stoi(value);

    return x;
}

void update(const char* path, int& new_value)
{
    std::ofstream file(path);
    file << new_value;
    
}