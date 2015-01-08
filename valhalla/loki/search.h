#ifndef VALHALLA_LOKI_SEARCH_H_
#define VALHALLA_LOKI_SEARCH_H_

#include <valhalla/baldr/location.h>
#include <valhalla/baldr/pathlocation.h>
#include <valhalla/baldr/graphreader.h>

namespace valhalla{
namespace loki{

/**
 * Notifies the search which type of precision should be used
 * Should it find the closest node to the input position
 * or instead try to use the geometry of the edges to find
 * an intermediate position along the edge. The former is
 * quite a bit faster but can be extremely inaccurate in
 * low density route networks
 */
enum class SearchStrategy : bool { NODE, EDGE };

/**
 * Find an location within the route network given an input location
 * same tiled route data and a search strategy
 *
 * @param location  the position which needs to be correlated to the route network
 * @param reader    and object used to access tiled route data TODO: switch this out for a proper cache
 * @param strategy  what type of search to do
 * @return pathLocation  the correlated data with in the tile that matches the input
 */
baldr::PathLocation Search(const baldr::Location& location, baldr::GraphReader& reader, const SearchStrategy strategy = SearchStrategy::NODE);

}
}

#endif  // VALHALLA_LOKI_SEARCH_H_