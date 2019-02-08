/** @file
 *
 *  Implementation of mesh.hpp
 *
 *  @note This class may need to be refactored to inherit from a "Renderable Class"
 *
 *  @copyright 2016-2019 Palm Studios and Mike Meinhardt (@perdedork)
 *
 *  @date 7-2-2019
 *
 *  @author Jesse Buhagiar (quaker762)
 *
 */
#include "SH3/graphics/mesh.hpp"
#include "SH3/arc/vfile.hpp"

using namespace sh3::graphics;

void CMesh::Load(const std::string& path)
{
    sh3::arc::vfile mdlFile;

    mdlFile.Open(mft, path);


}
