/*
 * function: func_02016C60
 * address:  0x02016C60
 * packet:   pkt_02016C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * mcss.c, the two-pass nibble fill over a0->f2c's 0x30-byte records.
 * EXACT* (870 bytes; the 872-byte listing extent carries 2 pad bytes).
 * Closed in wave 21 (lane B2) from 16 bytes out.  The lever is w2: it is
 * read raw into the guard (`w2 = R->f2c; if (w2 != 0)`) and shifted
 * later (`w2 >>= 12;`), and the pass-2 header follows pass 1's order,
 * sx2, sy2, w2, h2, then `i2 = 0; y = 0;`.  The raw w2 web spans the
 * sx2/sy2 reads and is coloured before the record pointer, which puts
 * the pointer in r1 and both zeros in r0, as the image has them.
 * History: docs/notes/pkt_02016C60.c.txt.
 *
 * symbols:
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AB80   0x0209AB80  arm
 *   _d2s            0x0209C508  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern double _s32_to_double(s32 v);
extern double func_0209AB80(double a, double b);
extern s32 _d2s(double d);
struct Rec
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0c;
  s32 f10;
  s32 f14;
  s32 f18;
  s32 f1c;
  s32 f20;
  s32 f24;
  s32 f28;
  s32 f2c;
  s32 f30;
  s32 f34;
  s32 f38;
};
struct Work
{
  u8 pad00[0x2c];
  s32 *f2c;
  u8 pada8[0xa8 - 0x30];
  s32 fa8;
  u8 padac[4];
  s32 fb0;
  u8 padb4[0x140 - 0xb4];
  u32 f140;
};
struct Task
{
  u8 **f00;
};
void func_02016C60(struct Work *a0, struct Task *a1)
{
  s32 scale;
  u8 *base;
  s32 k;
  s32 sx;
  s32 sy;
  s32 w;
  s32 h;
  s32 step;
  s32 nib;
  s32 found;
  s32 x;
  s32 y;
  s32 i;
  s32 j;
  s32 sx2;
  s32 sy2;
  s32 w2;
  s32 h2;
  s32 i2;
  s32 j2;
  s32 bw;
  s32 bh;
  s32 r;
  s32 c;
  s32 addr;
  s32 t;
  s32 v;
  s32 tmp1;
  s32 tmp2;
  s32 tmp3;
  s32 tmp4;
  s32 tmp5;
  s32 tmp8;
  s32 tmp10;
  if (a0->fb0 != 3)
  {
    return;
  }
  scale = _d2s(func_0209AB80(2.0, _s32_to_double(a0->fa8 + 2)));
  base = a1->f00[5];
  k = 0;
  while (((u32) k) < ((u32) a0->f2c[0]))
  {
    sx = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f1c >> 12;
    sy = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f20 >> 12;
    w = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f14 >> 12;
    h = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f18 >> 12;
    step = ((s32) ((a0->f140 << 4) >> 0x1c)) + 1;
    i = 0;
    y = 0;
    if (h > 0)
    {
      do
      {
        for (j = 0, x = 0; x < w; j++, x += step)
        {
          {
            s32 hi;
            if ((x + step) > w)
            {
              bw = w - (step * j);
            }
            else
            {
              bw = step;
            }
            if ((y + step) > h)
            {
              bh = h - (step * i);
            }
            else
            {
              bh = step;
            }
            found = 0;
            for (r = 0; r < bh; r++)
            {
              for (c = 0; c < bw; c++)
              {
                t = (sx + x) + c;
                tmp3 = (sy + y) + r;
                addr = (t / 2) + (tmp3 * scale);
                if (c & 1)
                {
                  v = (base[addr] & 0xf0) >> 4;
                }
                else
                {
                  v = base[addr] & 0x0f;
                }
                if (v != 0)
                {
                  found = v;
                  break;
                }
              }

              if (found != 0)
              {
                break;
              }
            }

            nib = (u8) found;
            hi = nib << 4;
            for (r = 0; r < bh; r++)
            {
              for (c = 0; c < bw; c++)
              {
                tmp10 = sx + x;
                t = tmp10 + c;
                tmp4 = sy + y;
                tmp1 = tmp4 + r;
                addr = (t / 2) + (tmp1 * scale);
                if (addr < (1 << 14))
                {
                  if (t & 1)
                  {
                    base[addr] = (base[addr] & 0x0f) | hi;
                  }
                  else
                  {
                    base[addr] = (base[addr] & 0xf0) | nib;
                  }
                }
              }

            }

          }
        }

        i++;
        y += step;
      }
      while (y < h);
    }
    w2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f2c;
    if (w2 != 0)
    {
      sx2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f34 >> 12;
      sy2 = ((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f38 >> 12;
      w2 >>= 12;
      h2 = (((struct Rec *) (((u8 *) a0->f2c) + (k * 0x30)))->f30 >> 12) << 1;
      i2 = 0;
      y = 0;
      if (h2 > 0)
      {
        do
        {
          for (j2 = 0, x = 0; x < w2; j2++, x += step)
          {
            {
              s32 hi2;
              if ((x + step) > w2)
              {
                bw = w2 - (step * j2);
              }
              else
              {
                bw = step;
              }
              if ((y + step) > h2)
              {
                bh = h2 - (step * i2);
              }
              else
              {
                bh = step;
              }
              found = 0;
              for (r = 0; r < bh; r++)
              {
                for (c = 0; c < bw; c++)
                {
                  t = (sx2 + x) + c;
                  tmp8 = (sy2 + y) + r;
                  addr = (t / 2) + (tmp8 * scale);
                  if (c & 1)
                  {
                    v = (base[addr] & 0xf0) >> 4;
                  }
                  else
                  {
                    v = base[addr] & 0x0f;
                  }
                  if (v != 0)
                  {
                    found = v;
                    break;
                  }
                }

                if (found != 0)
                {
                  break;
                }
              }

              nib = (u8) found;
              hi2 = nib << 4;
              for (r = 0; r < bh; r++)
              {
                for (c = 0; c < bw; c++)
                {
                  t = sx2 + x;
                  t = t + c;
                  tmp5 = sy2 + y;
                  tmp2 = tmp5 + r;
                  addr = (t / 2) + (tmp2 * scale);
                  if (addr < (1 << 14))
                  {
                    if (t & 1)
                    {
                      base[addr] = (base[addr] & 0x0f) | hi2;
                    }
                    else
                    {
                      base[addr] = (base[addr] & 0xf0) | nib;
                    }
                  }
                }

              }

            }
          }

          i2++;
          y += step;
        }
        while (y < h2);
      }
    }
    k++;
  }

}
