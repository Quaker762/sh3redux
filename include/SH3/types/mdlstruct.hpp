/** @file
 *
 *  SILENT HILL 3 .mdl data structures
 *
 *  @copyright 2016  Palm Studios and Mike M (@perdedork)
 *
 *  @date 6-2-2019
 *
 *  @author Jesse Buhagiar
 */

#ifndef _MDLSTRUCT_HPP_
#define _MDLSTRUCT_HPP_

#include <cstdint>
#include <vector>
#include <glm/glm.hpp>

#include "SH3/types/vertex.hpp"

/**
 * Model Data header. The first header found in a @c .mdl file
 */
struct mdl_header
{
    std::uint32_t       unknown;    /**< This is usually 0 */
    std::uint32_t       modelID;    /**< Unique Identifier for this model/mesh */
    std::uint32_t       numTex;     /**< Number of textures for this model */
    std::uint32_t       mdlSize;    /**< Size of the whole 3D mesh (minus the texture) */
    std::uint8_t        pad1[192];  /**< Misc. data. TODO: Work out what I am thankyou! :^) */
    glm::mat4           tMat1;      /**< Model Transformation matrix 1 */
    glm::mat4           tMat2;      /**< Model Transformation matrix 1 */
    glm::mat4           tMat3;      /**< Model Transformation matrix 1 */
    glm::mat4           tMat4;      /**< Model Transformation matrix 1 */
    std::uint8_t        pad2[68];   /**< Misc. data. TODO: Work out what I am thankyou! :^) */
    std::uint32_t       vertCount;  /**< Number of vertexes in the Vertex buffer */
    std::uint32_t       maybeVertPartSize /**< No fucking clue */
    std::uint32_t       pad3[112];  /**< Fills in space between the end of the header and the start of the vertices */
};

/**
 * Base model header. Not sure where this is in relation to @ref mdl_header
 */
struct mdl_base_header
{
    std::uint32_t pad;          /**< Pad DWORD */
    std::uint32_t mdlID;        /**< Model ID */
    std::uint32_t numTex;       /**< Number of textures included in this model */
    std::uint32_t texOffset;    /**< Offset to the embedded textures in this model file */
    std::uint32_t mdlSize;      /**< Size of this model (without textures) */
    std::uint32_t headerSize;   /**< Size of this header (??? ""size of initial base header"") */
    std::uint32_t pad2;
    std::uint32_t always1;      /**< Always seems to be 1. Perhaps some kind of flag?? TODO: Change this to 0 in IDA */
    std::uint32_t pad3[8];      /**< 32-byte pad */
};

/**
 *
 */
struct mdl_size_offset
{
    std::uint32_t headerSizeTexOffsets[4];  /**< This is a grouping always at the end of @ref mdl_base_header. It's size depends on the number of textures. 1-2=1, 3-4=2 etc. */
};

/**
 * SILENT HILL 3 .mdl data header.
 *
 * Describes matrix, texture and vertex data.
 */
struct mdl_data_header
{
    std::uint32_t mdlDataMagic;     /**< Magic number denoting that this header is a model data header */
    std::uint32_t always3;          /**< Always seems to be '3' (0b11) */
    std::uint32_t offsetMatSet1;    /**< Offset of the first matrix group */
    std::uint32_t numMatSet1;       /**< Number of matrices in set 1 */
    std::uint32_t offsetMatSeq1;    /**< Offset of the first matrix sequence group */
    std::uint32_t numMatSet2;       /**< Number of matrices in matrix set 2 */
    std::uint32_t offsetMatSeq2;    /**< Offset of the second matrix sequence group */
    std::uint32_t offsetMatSet2;    /**< Offset of the second matrix group */
    std::uint32_t numVertStruct;    /**< Number of vertex structures that contain a header, vertex data and index data */
    std::uint32_t numAltVertStruct; /**< Number of alternate vertex structures */
    std::uint32_t offsetAltVertHeader;
    std::uint32_t numTex;           /**< Number of textures (<i>AGAIN....</i>) */
    std::uint32_t offsetTexIndex;   /**< Offset of texture indicies (UV Coords??) */
    std::uint32_t totalModelTex;    /**< Total count of textures used for this mode, including embedded and textures in other places (.tex files) */
    std::uint32_t offsetTexSeq;     /**< Offset of data used to decide on primiteve texture and texture render states */

    // The following is straight from Mike's code and should be investigated ASAP. It could possibly relate to physics objects (Heather's hair/necklace)
    // or cutscene data?
    std::uint32_t qa4[2];
    std::uint32_t offsetQ5;
    std::uint32_t q6;
    std::uint32_t offsetQ7;
    std::uint32_t q8;
    std::uint32_t offsetQ9;
    std::uint32_t offsetQ10;
    std::uint32_t offsetQ11;
    std::uint32_t always1_1;      //?*?Seems to always be 3
    std::uint32_t fa2[6];
};

/**
 * Model vertex header
 */
struct mdl_vertex_header
{
    std::uint32_t   vertSegmentSize;        /**< Size of a header, vertex data and index data */
    std::uint32_t   pad1;
    std::uint32_t   headerSize;             /**< Size of this header */
    std::uint32_t   q1;
    std::uint32_t   indexCount;             /**< Number of indices */
    std::uint32_t   numAltSeq;              /**< Number of alternate sequence sets (there are 3 std::uint32_t's to a set) */
    std::uint32_t   altOffsetSeq1;          /**< Offset of what appears to be a sequence (animations?? Possibly cutscene related stuff). TODO: Investigate me! */
    std::uint32_t   numSeq1;                /**< Number of sequences in set 1 */
    std::uint32_t   offsetSeq1;             /**< Alternate offset of what appears to be a sequence */
    std::uint32_t   numSeq2;                /**< Number of sequences in set 2 */
    std::uint32_t   offsetSeq2;             /**< */
    std::uint32_t   q2;
    std::uint32_t   q3;
    std::uint32_t   always1;
    std::uint32_t   offsetTexIndex;         /**< Offset of texture index for vertex */
    std::uint32_t   offsetVerConst;         /**< Offset of vertex header constants */
    std::uint32_t   altHeaderSize;          /**< Alternate vertex header size */
    std::uint32_t   numVerts;               /**< Number of vertices */
    std::uint32_t   vertSectionSize;        /**< Size of JUST the vertex section */
    std::uint32_t   altNumIndex;            /**< Alternate number of indices */
    std::uint32_t   numFloatSets;           /**< Number of floating point sets (Mike thinks thses are vertices, weights or colours) */
    std::uint32_t   always1_2;
    float           floatSet0[4];           /**< Used if @ref numFloatSets is 4 ONLY */
    float           floatSet1[4];           /**< Used if @ref numFloatSets is 1, 2 or 4 */
    float           floatSet2[4];           /**< Used if @ref numFloatSets is 2 or 4 */
    float           floatSet3[4];           /**< Used if @ref numFloatSets is 4 ONLY */
};

/**
 * Model Primitive
 *
 * Combines a bit of data
 */
struct mdl_primitive
{
    mdl_vertex_header           header;         /**< Header for this primitive */
    std::vector<std::uint16_t>  altSeq1;
    std::vector<std::uint16_t>  seqData1;       /**< First sequence Data */
    std::vector<std::uint16_t>  seqData2;       /**< Second sequences data */
    std::uint16_t               texNum;         /**< Texture number */
    std::uint32_t               always8372234_1;
    uint32_t                    always2044_1;
    uint32_t                    always97_1;
    uint32_t                    f1;
    int                         vertSize;
    uint32_t                    texModify;
    std::vector<sh3_vertex>     vertData;       /**< Actual vertex data */
    std::vector<sh3_mdl_vertex> altVertData;    /**< Alternate vertex data */
    std::vector<std::uint32_t>  indices;        /**< Vertex indices list */
    // GLuint                   texID;          /**< TODO: Work out how to do texturing here! */
};


#endif
