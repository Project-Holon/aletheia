/*
 * unit:     no
 * function: func_0203D3F8
 * address:  0x0203D3F8
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
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
 *
 * TU: net.c.  The assert at 0x0203D478 passes "net.c" (0x020A7CA0), line
 * 1019, and the message "sendID < 7" (0x020A7CEC), which is where the name
 * of the second parameter comes from.
 *
 * The eight-argument send path.  Two early bail-outs return zero, and the
 * tail returns whatever func_02038C18 returns, so the value in r0 after the
 * final `bl` is the result and no epilogue materialises one.  `sendID ==
 * 0xff` means "broadcast", and leaves the byte mask at its initial 0xff;
 * any other value is turned into a one-hot bit, which is what the assert
 * guards.  The mask local is initialised before the first call, so its
 * `mov r7, #0xff` schedules up between the argument move and the `bl`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D3F8.c \
 *       --func func_0203D3F8 --addr 0x0203D3F8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern char g_020A7CA0[];
extern char g_020A7CEC[];

extern void *func_0203D798(void);
extern u32   func_0203D394(u32 entry);
extern u32   func_020395EC(u32 entry);
extern u32   func_02039468(u32 a, u32 b);
extern void  func_02034714(const char *file, u32 line, const char *msg);
extern u32   func_02038C18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g,
                  u32 h)
{
    u8 mask;

    func_0203D798();
    mask = 0xff;
    if (func_0203D394(entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC(entry)) != 0) {
        return 0;
    }
    if (sendID != 0xff) {
        if (sendID >= 7) {
            func_02034714(g_020A7CA0, 1019, g_020A7CEC);
        }
        mask = 1 << sendID;
    }
    return func_02038C18(c, e, d, f, func_020395EC(entry), mask, h);
}
