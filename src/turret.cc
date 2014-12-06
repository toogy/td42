#include <cfloat>
#include "map.hh"
#include "turret.hh"

Turret::Turret(unsigned life, float x, float y, float direction,
               unsigned recharge_time, unsigned fixed_res, unsigned power,
               float range)
   : Entity(life, x, y, direction, fixed_res, power, range),
   recharge_time_(recharge_time)
{
}

unsigned Turret::get_recharge_time()
{
  return this->recharge_time_;
}

void Turret::attack()
{
  if (spy_ != nullptr)
  {
    if (spy_->dead())
      spy_ = nullptr;
    else if (range_ < this->dist_from(*spy_)
             || !this->can_view(*spy_))
        spy_ = nullptr; // If Ennemy is too far... let's forget it.
  }
  if (spy_ == nullptr) // No ennemy... let's find one.
  {
    float dist = FLT_MAX;
    for (auto val : Map::turrets)
    {
      float tdist = this->dist_from(*val);
      if (tdist < dist && this->can_view(*val))
      {
        dist = tdist;
        spy_ = val;
      }
    }
  }
  if (spy_ != nullptr)
    spy_->take_attack(this->get_power());
}
