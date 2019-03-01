#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>
#include <array>

enum class School {
	Abjuration=0, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation
};

enum class CasterClass {
	Bard=0, Cleric, Druid, Paladin, Ranger, Sorcerer, Warlock, Wizard, ArcaneTrickster, EldritchKnight
};

enum class Subclass {
	Land=0, Lore, Draconic, Hunter, Life, Devotion, Berserker, Evocation, Fiend, Thief, OpenHand
};

enum class Sourcebook {
    PlayersHandbook=0, XanatharsGTE, SwordCoastAG
};

struct Spell {
	int index;
	std::string name;
	std::string description;
	std::string higherLevel;
	int page;
	std::string range;
	std::array<bool, 3> components;
	std::string material;
	bool ritual;
	std::string duration;
	bool concentration;
	std::string castingTime;
	int level;
    bool favorite;
	School school;
    Sourcebook sourcebook;
	std::vector<CasterClass> classes;
	std::vector<Subclass> subclasses;
};

#endif
