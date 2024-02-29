#include "Mage.hpp"


/**
  Default constructor.
  Default-initializes all private members. 
  Default character name: "NAMELESS". Booleans are default-initialized to False. 
  Default school of magic and weapon: "NONE". 
*/
Mage::Mage():school_of_magic_{"NONE"},weapon_{"NONE"},can_summon_incarnate_{false},Character()
{    
}

/**
  Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false.
  @param      : The character's school of magic (a const string reference). Valid schools: 
                [ELEMENTAL, NECROMANCY, ILLUSION]. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : The character's choice of weapon (a const string reference). 
                Valid weapons: [WAND, STAFF]
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable. Default to "NONE".
  @param      : A flag indicating whether the character is able to summon an 
                incarnate. Default to false.
  @post       : The private members are set to the values of the corresponding 
                parameters.
                REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                variables should be set to "NONE". 
*/
Mage::Mage(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& school_of_magic, const std::string& weapon, bool can_summon_incarnate) : Character(name, race, vitality, armor, level, enemy)
{
//Checking requirements for functions
//Making sure that school of magic becomes uppercase
std::string second_school = school_of_magic;
for (int i=0;i<school_of_magic.size();i++){
second_school[i] = std::toupper(school_of_magic[i]);
}

if(second_school != "ELEMENTAL" && second_school != "NECROMANCY" && second_school != "ILLUSION"){
    school_of_magic_ = "NONE"; // if not equaal to these, then set to NONE
}
else{
    school_of_magic_ = second_school; //if is equal, set equal to variable
}
std::string new_weapon = weapon;
for(int i=0;i<weapon.size();i++){
if(isalpha(weapon[i])){ //check for alphabetical characters

new_weapon[i] = std::toupper(weapon[i]); //set to uppercase
}

if(weapon != "WAND" && weapon != "STAFF"){
    weapon_ = "NONE"; //check specific cases
}
else{
    weapon_ = weapon;
}

can_summon_incarnate_ = can_summon_incarnate;
}
}

/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/
//setSchool

bool Mage::setSchool(const std::string& school_of_magic){
std::string second_school = school_of_magic;
for (int i=0;i<school_of_magic.size();i++){ //loop through string
    if(isalpha(school_of_magic[i])){ //check for alphabeticals

second_school[i] = std::toupper(school_of_magic[i]); //set to upper
}
}

if (second_school == "ELEMENTAL" || second_school == "NECROMANCY" || second_school == "ILLUSION"){
    school_of_magic_ = second_school;
    return true;
}
return false;
}

/**
  @return  : the string indicating the character's school of magic
**/
//getSchool
std::string Mage::getSchool() const{
    return school_of_magic_;
}

/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/
//setCastingWeapon
bool Mage::setCastingWeapon(const std::string& weapon){
std::string new_weapon = weapon;
for (int i =0;i<weapon.size(); i++){
    if(isalpha(weapon[i])){

    new_weapon[i] = std::toupper(weapon[i]); }
}
if (new_weapon == "WAND" || new_weapon == "STAFF"){
    weapon_ = new_weapon;
    return true;
}
return false;
}

/**
  @return  : the string indicating the character's weapon
**/
//getCastingWeapon
std::string Mage::getCastingWeapon() const{
    return weapon_;
}

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
//setIncarnateSummon
void Mage::setIncarnateSummon(const bool& can_summon_incarnate){
can_summon_incarnate_ = can_summon_incarnate;
}
/**
  @return  : the summon-incarnate flag
**/
//hasIncarnateSummon
bool Mage::hasIncarnateSummon() const{
    return can_summon_incarnate_;
}


