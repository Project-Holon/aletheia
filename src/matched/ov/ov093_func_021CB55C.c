/*
 * function: BTL_SERVER_FLOW_CalcLevelScaledExp
 * address: 0x021CB55C
 * packet: pkt_ov093_021CB55C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: the second block squares y in place (y *= y) and then multiplies the
 *   root by y: the product lands in the root copy register as in the original.
 *   Found in final push 2026-10-05 G1R4 after the Product helper and every
 *   named-yy form kept the product in the squared register.
 * symbols:
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   BTL_POKEPARAM_GetMaxLevelExp  0x021D6B6C  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
extern int func_0207C7B4(int x);
extern u32 BTL_POKEPARAM_GetMaxLevelExp(u8 *p);
u32 BTL_SERVER_FLOW_CalcLevelScaledExp(void *p, u32 a, u16 b, u16 c)
{
  int tmp;
  u32 tmp1;
  u32 r, lim;
  u32 x = (2 * c) + 10;
  u32 y = (c + b) + 10;
  u32 t1 = ((u32) (func_0207C7B4((int) ((x > 0) ? ((x * (1 << 12)) + 0.5f) : ((x * (1 << 12)) - 0.5f))) * (x * x))) >> 12;
  tmp = (int) ((y > 0) ? ((y * (1 << 12)) + 0.5f) : ((y * (1 << 12)) - 0.5f));
  tmp1 = func_0207C7B4(tmp);
  y *= y;
  r = ((a * t1) / ((y * tmp1) >> 12)) + 1;
  lim = BTL_POKEPARAM_GetMaxLevelExp(p);
  if (r > lim)
    r = lim;
  return r;
}
