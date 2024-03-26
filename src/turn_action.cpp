#include "turn_action.h"
#include "team.h"

ProductionChange::ProductionChange(int _delta) {
    actionType = TurnActionType::ProductionChange;
    delta = _delta;
}

void ProductionChange::SetOwner(int _owner_id) {
    owner_id = _owner_id;
}

int ProductionChange::GetDelta()  {
    return delta;
}

void ProductionChange::Complete(TurnData *turnData) const {
    std::cout << "Complete ProductionChange" << std::endl;
    for (auto team_ptr : turnData->teams) {
        if(team_ptr->ID() == owner_id) {
            team_ptr->set_production(team_ptr->get_production() + delta);
            break;
        }
    }
}

ProvokeStrike::ProvokeStrike() {
    actionType = TurnActionType::Strike;
    strikeTarget = nullptr;
}

void ProvokeStrike::Complete(TurnData *turnData) const {
    for (auto team_ptr : turnData->teams) {
        if(team_ptr->ID() == strikeTarget->ID()) {
            int p = team_ptr->get_production() / 2;
            if(p < 100) {
                p = 100;
            }
            team_ptr->set_production(p);
            break;
        }
    }
    std::cout << "Complete ProvokeStrike" << std::endl;
}

void ProvokeStrike::SetTarget(std::shared_ptr<Team> target) {
    strikeTarget = target;
}
