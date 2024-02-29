#ifndef MAGE_HPP_
#define MAGE_HPP_
#include <iostream>
#include <string>
#include <cctype>
#include "Character.hpp"

class Mage : public Character {

    private:

    std::string school_of_magic_;
    std::string weapon_;
    bool can_summon_incarnate_;

    public:
    //Default Constructor
    Mage();

    //Parameterized Constructor
    Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& school_of_magic = "NONE", const std::string& weapon = "NONE", bool can_summon_incarnate = false);
    



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

bool setSchool(const std::string& school_of_magic);

/**
  @return  : the string indicating the character's school of magic
**/
//getSchool
std::string getSchool() const;

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
bool setCastingWeapon(const std::string& weapon);

/**
  @return  : the string indicating the character's weapon
**/
//getCastingWeapon
std::string getCastingWeapon() const;

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/
//setIncarnateSummon
void setIncarnateSummon(const bool& can_summon_incarnate);

/**
  @return  : the summon-incarnate flag
**/
//hasIncarnateSummon
bool hasIncarnateSummon() const;

};
#endif
