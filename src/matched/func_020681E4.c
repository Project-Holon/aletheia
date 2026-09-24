/*
 * function: func_020681E4
 * address:  0x020681E4
 * packet:   pkt_02067FE4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A18F4     0x020A18F4  data
 *
 * NitroSystem g2d_CharCanvas.c GetCharIndex1D(cx, cy, areaWidth,
 * areaHeight, objWidth, objHeight): the character index of (x, y) inside
 * an OBJ-1D canvas tiled greedily with the largest OBJ that fits.  The last
 * two arguments are the current OBJ width/height shifts, rewritten each
 * round from GetMaxObjectSize's table g_020A18F4[log_h][log_w] (u8 pairs
 * widthShift, heightShift), with each log saturated at 3 and taken with an
 * in-place clz (MATH_ILog2 over MATH_CountLeadingZeros' `asm { clz x, x }`).
 *
 * Closed in wave 19 after 18 -> 10 in wave 11: the w log is computed IN
 * PLACE in the dying h-shift local `sh`, not in a fresh local.  With a named
 * log_w the two logs take each other's registers (18 out, in every
 * declaration order and with int, u32 or long logs); reusing sh puts log_w
 * in r6 with sh and log_h in r7, where the row pointer coalesces with the
 * next objWidth, as the image does.  1.1p1 is 240 bytes on this shape.
 */
typedef unsigned char u8;
typedef unsigned int u32;

struct Shift
{
  int w;
  int h;
};
extern const u8 g_020A18F4[4][4][2];

int func_020681E4(int x, int y, int w, int h, struct Shift s)
{
  int base = 0;
  int sh;
  int sw;
  int tmp;
  int tmp1;
  sw = s.w;
  sh = s.h;
  for (;;)
  {
    u32 ww;
    u32 hh;
    tmp = 0xFFFFFFFFu << sw;
    ww = ((u32) w) & tmp;
    hh = ((u32) h) & (0xFFFFFFFFu << sh);
    if (hh <= ((u32) y))
    {
      base += w * hh;
      if (ww <= ((u32) x))
      {
        h -= hh;
        base += ww * h;
        x -= ww;
        y -= hh;
        w -= ww;
      }
      else
      {
        w = ww;
        y -= hh;
        h -= hh;
      }
    }
    else
    {
      const u32 hinv = ~(0xFFFFFFFFu << sh);
      if (ww <= ((u32) x))
      {
        base += ww * hh;
        h = hh;
        x -= ww;
        w -= ww;
      }
      else
      {
        const u32 winv = ~(0xFFFFFFFFu << sw);
        base += ww * (y & (0xFFFFFFFFu << sh));
        tmp1 = x & (0xFFFFFFFFu << sw);
        base += tmp1 << sh;
        base += (y & hinv) << sw;
        return base + (x & winv);
      }
    }
    {
      int lh;
      const u8 *p;
      if (w >= 8) sh = 3; else { sh = w; asm { clz sh, sh } sh = 31 - sh; }
      if (h >= 8) lh = 3; else { lh = h; asm { clz lh, lh } lh = 31 - lh; }
      p = g_020A18F4[lh][sh];
      sw = (s.w = p[0]);
      sh = (s.h = p[1]);
    }
  }
}
