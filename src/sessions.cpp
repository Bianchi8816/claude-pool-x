// sessions.cpp — part of claude-pool-x.

#include "claudepoolx/sessions.h"

#include <cstdio>

namespace claudepoolx {

Sessions::Sessions(const std::string& config_path)
    : config_path_(config_path) {}

void Sessions::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Sessions::run() {
    if (verbose_) std::fprintf(stderr, "[claude-pool-x] sessions: run\n");
    // core logic lives here
    return true;
}

}  // namespace claudepoolx
