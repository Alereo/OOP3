#pragma once
#ifndef PCH_H
#define PCH_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <windows.h>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/serialization.hpp>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>


using namespace std;

#endif //PCH_H
