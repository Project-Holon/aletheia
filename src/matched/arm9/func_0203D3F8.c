/*
 * function: func_0203D3F8
 * address:  0x0203D3F8
 * packet:   pkt_0203D3F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7CA0     0x020A7CA0  data
 *   g_020A7CEC     0x020A7CEC  data
 *   func_0203D798  0x0203D798  arm
 *   func_0203D394  0x0203D394  arm
 *   func_020395EC  0x020395EC  arm
 *   func_02039468  0x02039468  arm
 *   func_02034714  0x02034714  arm
 *   func_02038C18  0x02038C18  arm
  * blocker:  label - 0x02038C18 and 0x020395EC each have exactly one branch in
 *           the image and it is the call inside this function, so `label` has
 *           no outside witness for either and no manifest entry covers them
 *           yet.  File those two addresses first and this graduates with no
 *           change to its C (every other site resolves).
 *
*/

typedef unsigned char u8;
typedef unsigned int  u32;

extern char g_020A7CA0[];
extern char g_020A7CEC[];

extern void *func_0203D798(void);
extern u32   func_0203D394(u32 entry);
extern int func_020395EC(void *a);
extern u32   func_02039468(u32 a, u32 b);
extern void  func_02034714(const char *file, u32 line, const char *msg);
extern u32   func_02038C18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h)
{
    u8 mask;

    func_0203D798();
    mask = 0xff;
    if (func_0203D394(entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    if (sendID != 0xff) {
        if (sendID >= 7) {
            func_02034714(g_020A7CA0, 1019, g_020A7CEC);
        }
        mask = 1 << sendID;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}
