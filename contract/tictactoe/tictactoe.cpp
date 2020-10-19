#include "tictactoe.hpp"
void tictactoe::create(const name &challenger, name &host) {
    require_auth(host);
    check(challenger != host, "Challenger should not be the same as the host.");

    // Check if game already exists
    games existingHostGames(get_self(), host.value);
    auto itr = existingHostGames.find(challenger.value);
    check(itr == existingHostGames.end(), "Game already exists.");

    existingHostGames.emplace(host, [&](auto &g) {
        g.challenger = challenger;
        g.host = host;
        g.turn = host;
    });
}