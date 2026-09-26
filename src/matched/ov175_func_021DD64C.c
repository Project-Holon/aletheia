/*
 * function: func_021DD64C
 * address:  0x021DD64C
 * packet:   pkt_ov175_021DD64C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   d_021E3730     0x021E3730  data
 *   d_021E3738     0x021E3738  data
 *   d_021E374C     0x021E374C  data
 *   d_021E375C     0x021E375C  data
 *   d_021E3770     0x021E3770  data
 *   d_021E3784     0x021E3784  data
 *   d_021E3798     0x021E3798  data
 *   d_021E37A8     0x021E37A8  data
 *   d_021E37B8     0x021E37B8  data
 *   d_021E37C8     0x021E37C8  data
 *   d_021E37DC     0x021E37DC  data
 *   d_021E37EC     0x021E37EC  data
 *   d_021E3800     0x021E3800  data
 *   d_021E3810     0x021E3810  data
 *   d_021E381C     0x021E381C  data
 *   d_021E3828     0x021E3828  data
 *   d_021E3838     0x021E3838  data
 *   d_021E3844     0x021E3844  data
 *
 * Nintendo WFC / Wi-Fi connection error-name to index table: a plain
 * strcmp-style probe (func_020948E0) against each known status string,
 * returning the string's index.  Seven indices (6 in the 9..0x14 range)
 * are skipped because they are not reachable from this pool; the caller
 * reads the dedicated return value from those.
 */

typedef int s32;

extern s32 func_020948E0(const char *a, const char *b);

extern char d_021E3730[];
extern char d_021E3738[];
extern char d_021E374C[];
extern char d_021E375C[];
extern char d_021E3770[];
extern char d_021E3784[];
extern char d_021E3798[];
extern char d_021E37A8[];
extern char d_021E37B8[];
extern char d_021E37C8[];
extern char d_021E37DC[];
extern char d_021E37EC[];
extern char d_021E3800[];
extern char d_021E3810[];
extern char d_021E381C[];
extern char d_021E3828[];
extern char d_021E3838[];
extern char d_021E3844[];

s32 func_021DD64C(const char *p)
{
    if (func_020948E0(p, d_021E3730) == 0)
        return 0;
    if (func_020948E0(p, d_021E3738) == 0)
        return 1;
    if (func_020948E0(p, d_021E374C) == 0)
        return 2;
    if (func_020948E0(p, d_021E375C) == 0)
        return 7;
    if (func_020948E0(p, d_021E3770) == 0)
        return 8;
    if (func_020948E0(p, d_021E3784) == 0)
        return 9;
    if (func_020948E0(p, d_021E3798) == 0)
        return 0xa;
    if (func_020948E0(p, d_021E37A8) == 0)
        return 0xb;
    if (func_020948E0(p, d_021E37B8) == 0)
        return 0xc;
    if (func_020948E0(p, d_021E37C8) == 0)
        return 0xd;
    if (func_020948E0(p, d_021E37DC) == 0)
        return 0xe;
    if (func_020948E0(p, d_021E37EC) == 0)
        return 0xf;
    if (func_020948E0(p, d_021E3800) == 0)
        return 0x10;
    if (func_020948E0(p, d_021E3810) == 0)
        return 0x11;
    if (func_020948E0(p, d_021E381C) == 0)
        return 0x12;
    if (func_020948E0(p, d_021E3828) == 0)
        return 0x13;
    if (func_020948E0(p, d_021E3838) == 0)
        return 0x14;
    return func_020948E0(p, d_021E3844) == 0 ? 0x15 : 0x16;
}
