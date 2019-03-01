#ifndef PARSE_H
#define PARSE_H

#include <fstream>
#include <vector>
#include <string>
#include <array>
#include "Classes.h"
#include "jsoncpp/json/json.h"
#include <QFile>

extern const std::vector<std::string> schoolNames;

extern const std::vector<std::string> casterNames;

extern const std::vector<std::string> subclassNames;

extern const std::vector<std::string> sourcebookNames;

extern const std::vector<std::string> sourcebookCodes;

extern const int N_SCHOOLS;

extern const int N_CASTERS;

extern const int N_SUBCLASSES;

extern const int N_SOURCES;

bool yn_to_bool(const std::string& yn);

std::string bool_to_yn(const bool& yn);

std::array<bool,3> components(const Json::Value& comps);

School school_from_name(const std::string& name);

Spell parse_spell(const Json::Value& root);

std::vector<Spell> read_spellfile(QFile* qspellfile);

/*template <class T>
int get_index(const std::vector<T>& v, const T& x);

template <class Enum>
Enum enum_from_name(const std::vector<std::string> allNames, const std::string& name);*/

// Template implementations
#include "Parse.tpp"

#endif
