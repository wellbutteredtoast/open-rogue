#ifndef META_BUILDINFO_HPP
#define META_BUILDINFO_HPP

#include <string>

class Meta {
public:
    std::string GetCompiler();

    std::string GetTargetArch();

    std::string GetLastGitCommit();

    std::string GetGitBranch();

    std::string GetBuildTimestamp();
};

#endif /* meta_buildinfo_hpp */