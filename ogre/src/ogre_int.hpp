#ifndef OGRE_INT_HPP
#define OGRE_INT_HPP

#include "ogreee.h"

// Options for convertions

// Global geometry options
// Use per-vertex normals or not
#define USE_NORMALS
// Use any textures (and UV mapping) or not
#define USE_TEXTURES
// Use 32-bit or 16-bit indices
//#define USE_INDICES32
#define USE_TERRAIN_TREES
#define USE_TERRAIN_OBJECTS

// Objects options
#ifdef USE_NORMALS
// Use per-vertex normals for objects or not
#define USE_OBJECTS_NORMALS
#endif
#ifdef USE_TEXTURES
// Use any textures (and UV mapping) for objects or not
#define USE_OBJECTS_TEXTURES
#endif

// Terrain options
#ifdef USE_NORMALS
// Use per-vertex normals for terrain or not
// TODO: Produces strange results with colours
#define USE_TERRAIN_NORMALS
#endif
#ifdef USE_TEXTURES
// Use any textures (and UV mapping) for terrain or not
#define USE_TERRAIN_TEXTURES
#endif
// Use per-vertex terrain colours or per-surface ones (TODO: Looks like it's not used in the game)
//#define USE_TERRAIN_VERTEX_COLOURS
// Limit number of terrain sectors to draw
#define USE_TERRAIN_VISIBILITY 10


#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#include "PagedGeometryConfig.h"
#include "PagedGeometry.h"
#include "BatchPage.h"
#include "OgreSubMesh.h"
#include "OgreSubEntity.h"
#include "OgreMeshManager.h"
#include "OgreHardwarePixelBuffer.h"
#include "OgreStaticGeometry.h"

#define OGRE_EE

#include "ee.h"

// Helper for Ogre resource names creation
class fmt
{
public:
	explicit fmt(const char* format, ...)
	{
		va_list ap;
		va_start(ap, format);
		vsprintf(str, format, ap);
		va_end(ap);
	}
	operator Ogre::String(void) const
	{
		return str;
	}

private:
	char str[256];

	fmt(fmt&);
	void operator =(fmt&);
};

#define DEFINE_NAME(name, args, format, params) \
struct name : private fmt \
{ \
	explicit name(args) \
		: fmt(format, params) \
	{ \
	} \
	using fmt::operator Ogre::String; \
}

#include "ogre_set.hpp"
#include "ogre_geometry.hpp"
#include "ogre_animation.hpp"
#include "ogre_objects.hpp"
#include "ogre_scenes.hpp"

#define _ ,
DEFINE_NAME(MaterialName, unsigned index, "MATERIAL_%u", index);
DEFINE_NAME(MaterialAnimationName, unsigned index _ unsigned frame, "MATERIAL_%u_%u", index _ frame);
DEFINE_NAME(ObjectName, unsigned index, "OBJECT_%04X", index);
DEFINE_NAME(TextureName, unsigned index, "TEXTURE_%u", index);
DEFINE_NAME(KeyframeAnimationName, unsigned index, "ANIMATION_%u", index);
DEFINE_NAME(TerrainObject, unsigned z _ unsigned x, "TERRAIN_%u_%u", z _ x);
DEFINE_NAME(TerrainStaticGeometry, unsigned z _ unsigned x, "TERRAIN_STATIC_%u_%u", z _ x);
DEFINE_NAME(TerrainTreeObject, void, "TERRAIN_TREE_OBJECT", 0);
DEFINE_NAME(TerrainTree, unsigned z _ unsigned x, "TERRAIN_TREE_%u_%u", z _ x);
#undef _

#undef DEFINE_NAME

#endif