/*
 * function: func_021CBD48
 * address: 0x021CBD48
 * packet: pkt_ov093_021CBD48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: Thumb bx-pc linker veneer 0x021CBE98 points to 0x0689C9A0,
 * outside covered regions. Its call has no external witness; tu split
 * census reports zero witnesses and no viable partition. The trailing
 * 16 bytes are that veneer, not compiled C.
 * symbols:
 *   func_021D5814 0x021D5814 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021B8724 0x021B8724 thumb ov093
 *   TIMEZONE_GetTimeZoneOfHour 0x020113F0 thumb
 *   func_021CBE98 0x021CBE98 thumb ov093
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D5814(void *,int);
extern int func_021BA1A8(char **p, int m);
extern char *func_021B8714(char **);
extern int func_021D59B4(u8 *p, int k);
extern int func_021B8724(char *p, void *m);
extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);
extern int func_021CBE98(u16);
int func_021CBD48(u8 *p, void *unused, void *q, int k)
{
    u16 n;
    float f;
    int value;
    u8 flag;
    switch (k) {
    case 3: return 0x1800;
    case 2: return 0x2000;
    case 6:
        if (func_021D5814(q,10) || func_021D5814(q,6)) return 0x3000;
        break;
    case 7:
        if (func_021BA1A8(*(void **)(p+4),1)) return 0x3800;
        if (*(int *)(func_021B8714(*(char ***)(p+4))+4) == 6) return 0x3800;
        break;
    case 8:
        n = func_021D59B4(q,15);
        if (n < 30) {
            n = 41 - n;
            if (n > 40) n = 40;
            if (n != 0) f = 0.5f + (float)(n << 12);
            else f = (float)(n << 12) - 0.5f;
            return (int)f / 10;
        }
        break;
    case 9:
        if (func_021B8724(*(void **)(p+4),q)) return 0x3000;
        break;
    case 10:
        value = *(int *)(p+0x10)*0x4cd+0x1000;
        if (value > 0x4000) value = 0x4000;
        return value;
    case 13:
        p = (u8 *)func_021B8714(*(char ***)(p+4));
        flag = TIMEZONE_GetTimeZoneOfHour(p[9],p[12]);
        if ((unsigned)(*(int *)p - 4) <= 1) return 0x3800;
        if (func_021CBE98(*(int *)p)) {
            if ((u8)(flag + 253) <= 1) return 0x3800;
        }
        break;
    case 15:
        if (*(int *)(p+0x10) == 0) return 0x5000;
        break;
    default: break;
    }
    return 0x1000;
}
