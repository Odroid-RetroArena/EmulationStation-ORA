#pragma once
#ifndef ES_CORE_UTIL_H
#define ES_CORE_UTIL_H

#include <boost/filesystem/path.hpp>

std::string strToUpper(const char* from);
std::string& strToUpper(std::string& str);
std::string strToUpper(const std::string& str);

std::string getCanonicalPath(const std::string& str);

boost::filesystem::path removeCommonPathUsingStrings(const boost::filesystem::path& path, const boost::filesystem::path& relativeTo, bool& contains);
// example: removeCommonPath("/home/pi/roms/nes/foo/bar.nes", "/home/pi/roms/nes/") returns "foo/bar.nes"
boost::filesystem::path removeCommonPath(const boost::filesystem::path& path, const boost::filesystem::path& relativeTo, bool& contains);

// usage: makeRelativePath("/path/to/my/thing.sfc", "/path/to") -> "./my/thing.sfc"
// usage: makeRelativePath("/home/pi/my/thing.sfc", "/path/to", true) -> "~/my/thing.sfc"
boost::filesystem::path makeRelativePath(const boost::filesystem::path& path, const boost::filesystem::path& relativeTo, bool allowHome);

// expands "./my/path.sfc" to "[relativeTo]/my/path.sfc"
// if allowHome is true, also expands "~/my/path.sfc" to "/home/pi/my/path.sfc"
boost::filesystem::path resolvePath(const boost::filesystem::path& path, const boost::filesystem::path& relativeTo, bool allowHome);

std::string escapePath(const boost::filesystem::path& path);

std::string strreplace(std::string str, const std::string& replace, const std::string& with);

// Remove (.*) and [.*] from str
std::string removeParenthesis(const std::string& str);

// split a comma-separated string into a vector
std::vector<std::string> commaStringToVector(std::string commaString);

// turn a vector of strings into a comma-separated string
std::string vectorToCommaString(std::vector<std::string> stringVector);

#endif // ES_CORE_UTIL_H
