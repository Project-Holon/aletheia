/*
 * function: BR_BTN_CopyRecord
 * address: 0x021FAE70
 * packet: pkt_ov186_021FAE70
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   BR_BTN_SetMode 0x021FADB8 thumb ov186
 *   d_02200D18 0x02200D18 data a1
 */
typedef struct Record { int state; int mode; int words[15]; } Record;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void BR_BTN_SetMode(char *ctx, int mode);
extern char d_02200D18[];
void BR_BTN_CopyRecord(void *ctx, Record *dest, const Record *source, int mode)
{
    if (dest->state != 0) func_02034714(d_02200D18, 0, d_02200D18);
    if (source->state != 1) func_02034714(d_02200D18, 0, d_02200D18);
    *dest = *source;
    if (source->mode != mode) BR_BTN_SetMode((char *)dest, mode);
}
