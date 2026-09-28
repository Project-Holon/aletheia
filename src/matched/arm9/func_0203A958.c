/*
 * function: func_0203A958
 * address:  0x0203A958
 * packet:   pkt_0203A958
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D8     0x021469D8  data
 *   func_020399A8  0x020399A8  arm
 *   func_0203A81C  0x0203A81C  arm
 *   func_02034714  0x02034714  arm
 *   sNet3730       0x020A7AF8  data
 *   sNet3733       0x020A7B20  data
 *   sNet3734       0x020A7B50  data
 *
 * net_command.c: register the command record a2 in slot a0 (0xff -> 8) of
 * the 0x14-stride table at g_021469D8 + 0xb8, asserting the slot was free
 * (line 0x1ff) and that func_0203A81C accepted it (line 0x203).
 *
 * Closed from docs/notes/pkt_0203A958.c.txt (39 bytes out) by the same
 * lever as func_0203A020 in net_handle.c: the record parameter is
 * `const u8 *a2`, which lets the `*(u32 *)a2` load hoist above the in-use
 * strb and the five halfword copies interleave as the image has them.
 * The permuter's old `tmp` local for the +6 halfword is then unneeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A958.c  *       --func func_0203A958 --addr 0x0203A958 --arm --cc 1.1p1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *g_021469D8;
extern int func_020399A8(void);
extern int func_0203A81C(int a0, int a1, int a2);
extern void func_02034714(char *a, u32 b, char *c);
extern char sNet3730[];
extern char sNet3733[];
extern char sNet3734[];
void func_0203A958(int a0, int a1, const u8 *a2, int a3, int a4)
{
  int i;
  u16 v0, v2, v8, v6;
  i = a0;
  if (a0 == 0xff)
    i = 8;
  if (a4 != func_020399A8())
    return;
  if (func_0203A81C(*((u16 *) (a2 + 6)), a0, *((u32 *) a2)) == 0)
    return;
  if ((*((u8 *) ((g_021469D8 + (i * 0x14)) + 0xca))) != 0)
    func_02034714(sNet3730, 0x1ff, sNet3733);
  *((u8 *) ((g_021469D8 + (i * 0x14)) + 0xca)) = 1;
  {
    u32 w = *((u32 *) a2);
    *((u32 *) ((g_021469D8 + (i * 0x14)) + 0xb8)) = w;
    *((u32 *) ((g_021469D8 + (i * 0x14)) + 0xbc)) = func_0203A81C(*((u16 *) (a2 + 6)), a0, w);
  }
  if ((*((u32 *) ((g_021469D8 + (i * 0x14)) + 0xbc))) == 0)
    func_02034714(sNet3730, 0x203, sNet3734);
  v0 = *((u16 *) (a2 + 6));
  v2 = *((u16 *) (a2 + 8));
  v8 = *((u16 *) (a2 + 0xa));
  v6 = *((u16 *) (a2 + 4));
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc0)) = v0;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc2)) = v2;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc8)) = v8;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc6)) = v6;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc4)) = 0;
}
