/*
 * function: func_021F582C
 * address: 0x021F582C
 * packet: pkt_ov077_021F582C
 * region: ov077
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Draw callback of the grid effect: draws the w*h grid of textured quads
 * through the geometry engine ports. Each cell is moved to its position,
 * scaled to its size, turned by its Y and Z angles (index = angle >> 4 into
 * the sin/cos table) and drawn with the quad's texture coordinates.
 *
 * The only wildcard is the scale vector template (0x021F5A58 = 0x1000 x3,
 * compiler data right after the pool, read only by this function), written
 * as the initialiser of `sc` (mwcc copies its template).
 *
 * Levers that matched it (register allocation is the whole difficulty):
 * the far texture corner as locals right after px/py; named col/row locals
 * with the column first in the products; the aggregates sit in an inner
 * block after the five setup stores so the file also matches with --lang c;
 * Translate and Scale as inline helpers (arguments first, as the original
 * loads z, y, x before the three stores); the cell pointer as the first
 * statement of the loop; px, py declared at function scope before n, a, b.
 *
 * symbols:
 *   func_0207AF1C 0x0207AF1C thumb
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207D934 0x0207D934 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021F5A58 0x021F5A58 data a4
 */
#include "../enceff_base_types.h"
#include "../enceff_grid_types.h"
#include "../enceff_g3_inline.h"

extern s16 d_020A1B38[];
extern void func_0207AF1C(Mtx33 *mtx, int sinValue, int cosValue);
extern void func_0207AF38(Mtx33 *mtx, int sinValue, int cosValue);
extern void func_0207D934(const Mtx33 *mtx);

void func_021F582C(EncEffGridWork *work)
{
    REG_MTX_PUSH = 0;
    REG_DIF_AMB = 0x7FFF7FFF;
    REG_SPE_EMI = 0x4210;
    REG_LIGHT_COLOR = 0x7FFF;
    REG_POLYGON_ATTR = 0x001F0081;
    {
        VecFx32 pos = {0, 0, 0};
        VecFx32 scale = {0x1000, 0x1000, 0x1000};
        Mtx33 mtx;
        int px, py, farX, farY;
        int cols, rows, cellCount, pixelWidth, pixelHeight, i, angleIndex, col, row;
        rows = work->rows;
        cols = work->cols;
        cellCount = cols * rows;
        pixelWidth = (0x20 / cols) << 3;
        pixelHeight = (0x18 / rows) << 3;
        scale.x = (pixelWidth / 8) << 12;
        scale.y = (pixelHeight / 8) << 12;
        for (i = 0; i < cellCount; i++) {
            EncEffGridCell *cell = &work->cell[i];
            REG_MTX_PUSH = 0;
            cols = work->cols;
            pos = cell->pos;
            col = i % cols;
            px = (col * pixelWidth) << 12;
            row = i / cols;
            py = (row * pixelHeight) << 12;
            farX = px + (pixelWidth << 12);
            farY = py + (pixelHeight << 12);
            G3_Translate(pos.x, pos.y, pos.z);
            G3_Scale(scale.x, scale.y, scale.z);
            angleIndex = cell->angleY >> 4;
            func_0207AF1C(&mtx, d_020A1B38[angleIndex * 2], d_020A1B38[angleIndex * 2 + 1]);
            func_0207D934(&mtx);
            angleIndex = cell->angleZ >> 4;
            func_0207AF38(&mtx, d_020A1B38[angleIndex * 2], d_020A1B38[angleIndex * 2 + 1]);
            func_0207D934(&mtx);
            REG_BEGIN_VTXS = 1;
            REG_NORMAL = 0x20000000;
            G3_TexCoord(px, py);
            REG_VTX_16 = 0x4000C000; REG_VTX_16 = 0;
            G3_TexCoord(px, farY);
            REG_VTX_16 = 0xC000C000; REG_VTX_16 = 0;
            G3_TexCoord(farX, farY);
            REG_VTX_16 = 0xC0004000; REG_VTX_16 = 0;
            G3_TexCoord(farX, py);
            REG_VTX_16 = 0x40004000; REG_VTX_16 = 0;
            REG_END_VTXS = 0;
            REG_MTX_POP = 1;
        }
        REG_MTX_POP = 1;
    }
}
