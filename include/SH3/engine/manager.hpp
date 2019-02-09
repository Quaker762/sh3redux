/** @file
 *
 *  Manager template class. All specialised resource managers should inherit this class.
 *
 *  @copyright 2016-2019 Palm Studios
 *
 *  @date 7-2-2019
 *
 *  @author Jesse Buhagiar (quaker762)
 *
 */
#ifndef _MANAGER_HPP_
#define _MANAGER_HPP_

#include <unordered_map>

namespace sh3 { namespace engine {

/**
 * Manager base template class
 *
 * T is the resource in which we want to manage
 * mapType is how we want to map the resource for lookup, via string, numerical ID etc.
 *
 */
template <typename T, typename KEY>
class CManager
{
public:
    /**
     *
     */
    CManager() = delete;

    /**
     *
     */
    virtual ~CManager();

    /**
     * Add a resource to the map
     *
     * @param obj   The object that we want to add to the map
     * @oaram find  The key to lookup this resource
     */
    virtual void MapResource(T obj, KEY find) = 0;

    /**
     * Purge the map of all resources, calling the destructor of each object in the map
     */
    void Purge(void) {resourceMap.clear();};
protected:
    std::unordered_map<KEY, T>  resourceMap;    /**< Resource map */
    std::size_t                 numElems;       /**< Number of resources stored in this map */
};

}}




#endif
