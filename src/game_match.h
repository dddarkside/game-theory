#ifndef GAME_THEORY_GAME_MATCH_H
#define GAME_THEORY_GAME_MATCH_H

#include <vector>
#include <memory>
#include "turn_action.h"

class ITurnAction;
class Team;

class MatchActionsFactory {
public:
    virtual std::vector<std::shared_ptr<ITurnAction>> Create() const = 0;
    virtual ~MatchActionsFactory() {}
};

class DefaultMatchActions : public MatchActionsFactory {
public:
    [[nodiscard]] std::vector<std::shared_ptr<ITurnAction>> Create() const override;
};

class GameMatch {
    /*
     *  Игровой матч состоящий из 14 ходов
     *  Содержит информацию о игре, командах, и т.д.
     *  Управляет циклом игры, производит ходы
     */
private:
    std::vector<std::shared_ptr<Team>> teams;
    std::vector<std::shared_ptr<Team>> strikeTeams;

    void setup_teams();
    void complete_turn();
    void compute_turn_results();

public:
    void start();

    ~GameMatch();
};


#endif //GAME_THEORY_GAME_MATCH_H
