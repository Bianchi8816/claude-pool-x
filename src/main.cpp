// main.cpp — entry point. Wires config and subsystems together.

#include "claudepoolx/settings.h"
#include "claudepoolx/sessions.h"
#include "claudepoolx/rotate.h"
#include "claudepoolx/proxy.h"
#include "claudepoolx/cli.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    claudepoolx::Settings settings = claudepoolx::Settings::load_default();
    claudepoolx::Sessions sessions(settings.store_path);
    claudepoolx::Rotate rotate(settings.store_path);
    claudepoolx::Proxy proxy(settings.store_path);
    claudepoolx::Cli cli(settings.store_path);
    std::fprintf(stderr, "[claude-pool-x] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
