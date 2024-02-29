#include "Scoundrel.hpp"


/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
*/
Scoundrel::Scoundrel():dagger_{WOOD},faction_{"NONE"},has_disguise_{false},Character()
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
    @param      : The character's dagger type (a const string reference).
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the dagger enum. Default to WOOD
    @param      : The character's Faction (a const string reference). 
                  Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
                  String inputs can be in lowercase, but must be converted to 
                  uppercase when setting the variable. Default to "NONE"
    @param      : A flag indicating whether the character has a disguise. Default to false
    @post       : The private members are set to the values of the corresponding 
                  parameters.
                 If the dagger type is not provided or invalid, the variable should 
                  be set to WOOD. 
                 If the Faction is not provided or invalid, the variable should be 
                  set to "NONE". 
*/
Scoundrel::Scoundrel(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& dagger, const std::string& faction, bool has_disguise) : Character(name, race, vitality, armor, level, enemy){



//checks requirements for functions
std::string second_dagger = dagger;
for (int i=0;i<dagger.size();i++){
    second_dagger[i] = std::toupper(dagger[i]);
}
if (second_dagger == "WOOD"){
    dagger_ = WOOD;
} else if (second_dagger == "BRONZE"){
    dagger_ = BRONZE;
} else if (second_dagger == "IRON"){
    dagger_ = IRON;
} else if (second_dagger == "STEEL"){
    dagger_ = STEEL;
} else if (second_dagger == "MITHRIL"){
    dagger_ = MITHRIL;
} else if (second_dagger == "ADAMANT"){
    dagger_ = ADAMANT;
} else if (second_dagger == "RUNE"){
    dagger_ = RUNE;
} else {
    dagger_ = WOOD;
}

std::string new_faction = faction;
for (int i = 0; i<faction.size(); i++){
    if(isalpha(faction[i])){ //check for alphabeticals
         new_faction[i] = std::toupper(faction[i]); //convert to uppercase
    }
}
if (new_faction == "CUTPURSE" || new_faction == "SHADOWBLADE" || new_faction == "SILVERTONGUE"){
    faction_ = new_faction;
} else{
    faction_ = "NONE";
}

has_disguise_ = has_disguise;

}
/**
   @param     : a reference to a string representing the dagger type
   @post      : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the dagger type is not valid (i.e, is one of the following: 
                [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
**/
//setDagger
void Scoundrel::setDagger(const std::string& dagger){
std::string second_dagger = dagger;
for (int i=0;i<dagger.size();i++){
    second_dagger[i] = std::toupper(dagger[i]);
}


if (second_dagger == "WOOD"){
    dagger_ = WOOD;
} else if (second_dagger == "BRONZE"){
    dagger_ = BRONZE;
} else if (second_dagger == "IRON"){
    dagger_ = IRON;
} else if (second_dagger == "STEEL"){
    dagger_ = STEEL;
} else if (second_dagger == "MITHRIL"){
    dagger_ = MITHRIL;
} else if (second_dagger == "ADAMANT"){
    dagger_ = ADAMANT;
} else if (second_dagger == "RUNE"){
    dagger_ = RUNE;
} else {
    dagger_ = WOOD;
}

}

/**
  @return     : the string indicating the character's dagger type
**/
//getDagger
std::string Scoundrel::getDagger() const{
    switch (dagger_){
        case WOOD:
        return "WOOD";
        case BRONZE:
        return "BRONZE";
        case IRON:
        return "IRON";
        case STEEL:
        return "STEEL";
        case MITHRIL:
        return "MITHRIL";
        case ADAMANT:
        return "ADAMANT";
        case RUNE:
        return "RUNE";
        default:
        return "WOOD";
    }
}

/**
    @param    : a reference to a string representing the character's Faction
    @post     : sets the private member variable to the value of the parameter. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the provided faction is not one of the following: 
               [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
               do nothing and return false.
    @return   : true if setting the variable was successful, false otherwise.
**/
//setFaction
bool Scoundrel::setFaction(const std::string& faction){
std::string new_faction = faction;
for (int i = 0; i<faction.size(); i++){
    if(isalpha(faction[i])){
         new_faction[i] = std::toupper(faction[i]); //set to upper
    }
}
if (new_faction == "NONE" || new_faction == "CUTPURSE" || new_faction == "SHADOWBLADE" || new_faction == "SILVERTONGUE"){
    faction_ = new_faction;
    return true;
}
return false;
}

/**
  @return  : the string indicating the character's Faction
**/
//getFaction
std::string Scoundrel::getFaction() const{
    return faction_;
}

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character has a disguise
**/
//setDisguise
void Scoundrel::setDisguise(const bool& has_disguise){
has_disguise_ = has_disguise;
}


/**
  @return  : the disguise flag
**/
//hasDisguise
bool Scoundrel::hasDisguise() const{
    return has_disguise_;
}














