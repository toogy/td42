#ifndef MAP_HH
# define MAP_HH

# include <list>
#include <vector>
# include <memory>

# include "mob.hh"
# include "turret.hh"

enum CellType
{
    Empty,
    Tower
};

class Map
{
  public:
    std::list<std::shared_ptr<Mob>> ennemies;
    std::list<std::shared_ptr<Turret>> turrets;
    std::vector<std::vector<CellType>> cells;

    std::list<std::pair<int, int>> neighbours(
            const std::pair<int, int>& pos) const;

    int cost(const std::pair<int, int>& start,
             const std::pair<int, int>& end) const;

    bool is_visitable(const std::pair<int, int>& node) const;
};

#endif /* !MAP_HH */
