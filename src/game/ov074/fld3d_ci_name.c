/*
 * file:     fld3d_ci_name.c
 * unit:     yes
 * function: FLD3D_CI_GetNameRow
 * address:  0x021F54E0
 * region:   ov074
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Overlay 74 (loaded by FLD3D_CI_StartNameSequence of ov021 with GF_OVERLAY_Load(0x4A),
 * unloaded again before it returns) holds the table of the field 3D name cut-ins and
 * the getter for one row.  It is data with a single accessor; the overlay has no
 * other code and its static-initialiser entry is empty.
 *
 * A row is five words: the cut-in sequence id (FLD3D_CI_StartSequence takes its low
 * byte), the icon character file index, the icon palette file index, the name message
 * id, and the name layout (0: no extra task, 1: second name line, 2: extra task
 * without a second name).  The last six rows only set a sequence id.
 *
 * symbols:
 *   g_Fld3dCiNameRows  0x021F54F0  data  ov074  a4
 */
#include "../types.h"

typedef struct Fld3dCiNameRow {
    u32 sequenceId;
    u32 chrFile;
    u32 plttFile;
    u32 nameMsgId;
    u32 nameLayout;
} Fld3dCiNameRow;

extern const Fld3dCiNameRow g_Fld3dCiNameRows[];

/* Returns the table row of cut-in index. */
const Fld3dCiNameRow *FLD3D_CI_GetNameRow(int index)
{
    return &g_Fld3dCiNameRows[index];
}

const Fld3dCiNameRow g_Fld3dCiNameRows[] = {
    {13, 2, 24, 1, 1},
    {13, 3, 25, 2, 1},
    {13, 4, 26, 3, 1},
    {13, 5, 27, 4, 1},
    {13, 6, 28, 5, 1},
    {13, 7, 29, 6, 1},
    {13, 8, 30, 7, 1},
    {13, 9, 31, 8, 1},
    {13, 10, 32, 9, 1},
    {13, 11, 33, 10, 1},
    {13, 12, 34, 11, 1},
    {13, 13, 35, 12, 1},
    {13, 14, 36, 13, 1},
    {14, 15, 37, 14, 1},
    {14, 16, 38, 15, 1},
    {14, 17, 39, 16, 1},
    {14, 18, 40, 17, 1},
    {14, 19, 41, 18, 1},
    {16, 20, 42, 19, 2},
    {16, 21, 43, 20, 2},
    {15, 0, 0, 0, 0},
    {25, 0, 0, 0, 0},
    {23, 0, 0, 0, 0},
    {24, 0, 0, 0, 0},
    {21, 0, 0, 0, 0},
    {22, 0, 0, 0, 0},
};
