#include "Ranger.hpp"

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/
Ranger::Ranger():arrows_{},affinities_{},has_companion_{false},Character(){

}


/**
   Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false
  @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Invalid arrows are those with non-positive quantities or invalid types.
                If the vector contains invalid arrows, those arrows are discarded. 
                Default to empty vector
  @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                String inputs can be in lowercase, but must be converted to uppercase.
                If the vector contains invalid affinities, those affinities are discarded.
                Default to empty vector
  @param      : A flag indicating whether the character is able to recruit an animal companion. 
                Default to false
  @post       : The private members are set to the values of the corresponding parameters
*/
Ranger::Ranger(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, std::vector<Arrows> arrows, std::vector<std::string> affinities, bool has_companion) : Character(name, race, vitality, armor, level, enemy){

has_companion_ = has_companion;

for(int i=0;i<affinities.size();i++){
addAffinity(affinities[i]);
}

for(int i=0;i<arrows.size();i++){
    addArrows(arrows[i].type_, arrows[i].quantity_);
}

}

/**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
**/
//addArrows
bool Ranger::addArrows(const std::string& arrows, const int& quantity){
    std::string new_type = arrows;
    for(int i=0;i<new_type.size();i++){
        new_type[i] = std::toupper(new_type[i]);
    }
    if (new_type != "WOOD" && new_type != "FIRE" && new_type != "WATER" && new_type != "POISON" && new_type != "BLOOD"){
        return false;
    }
    if (quantity <= 0){
        return false;
    }
    for (int i=0;i<arrows_.size();i++){

        if(arrows_[i].type_ == new_type){
            arrows_[i].quantity_ += quantity;
            return true;
        }
    }
    //if not found add arrow to the vector
    arrows_.push_back({new_type, quantity});
    return true;
}


/**
  @return     : a vector of the Character's arrows
**/
//getArrows
std::vector<Arrows> Ranger::getArrows() const{
    return arrows_;
}

/**
    @param    : a reference to string representing the arrow type
    @post     : If the character has the listed arrow AND enough arrows to fire one, 
                the quantity of remaining arrows in the vector is updated.
                Lowercase valid arrow types are accepted but converted to uppercase.
                If firing the last arrow, simply decrement the quantity to 0.
    @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
**/
//fireArrow
bool Ranger::fireArrow(const std::string& arrows){
    std::string new_fire = arrows;
    for(int i=0; i<new_fire.size();i++){
        new_fire[i] = std::toupper(new_fire[i]);
    }
    if (new_fire != "WOOD" && new_fire != "FIRE" && new_fire != "WATER" && new_fire != "POISON" && new_fire != "BLOOD"){
        return false;
    }
for(int i=0;i<arrows_.size();i++){
 if(arrows_[i].type_ == new_fire && arrows_[i].quantity_ > 0){
        //decrement when found
        arrows_[i].quantity_ -=1;
        return true;
    }
    }
    return false;
}

/**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
              String inputs can be in lowercase, but must be converted to uppercase when 
              setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
**/
//addAffinity
bool Ranger::addAffinity(const std::string& affinity){
    std::string new_affinity = affinity;
    for(int i =0; i<new_affinity.size();i++){
        if(isalpha(new_affinity[i])){
        new_affinity[i] = std::toupper(new_affinity[i]);
    }
    }
    if(new_affinity == "FIRE" || new_affinity == "WATER" || new_affinity == "POISON" || new_affinity == "BLOOD"){

        for(int j =0;j<affinities_.size(); j++){
            if (affinities_[j] == new_affinity) {
                return false;
            }
        }
        affinities_.push_back(new_affinity);
        return true;
    }
    return false;
}

/**
  @return     : a vector of the Character's affinities
**/
//getAffinities
std::vector<std::string> Ranger::getAffinities() const{
    return affinities_;
}

/**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
**/
//setCompanion
void Ranger::setCompanion(const bool& has_companion){
    has_companion_ = has_companion;
}

/**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
**/
//getCompanion
bool Ranger::getCompanion() const{
    return has_companion_;
}

