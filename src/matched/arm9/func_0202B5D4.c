/*
 * function: ISS_SYS_DeleteSubsystems
 * address:  0x0202B5D4
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202B6AC, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 * status:   EXACT
 * closed:   blocker ISS_SYS_DeleteSwitch.c is now a manifest entry (matched class)

 *
 * symbols:
 *   ISS_SYS_DeleteRoad  0x0202B66C  thumb
 *   ISS_SYS_DeleteCity  0x0202B67C  thumb
 *   ISS_SYS_DeleteDungeon  0x0202B68C  thumb
 *   ISS_SYS_DeleteZone  0x0202B69C  thumb
 *   ISS_SYS_DeleteSwitch  0x0202B6AC  thumb
 *   ISS_SYS_Delete3ds  0x0202B6BC  thumb
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void ISS_SYS_DeleteRoad(struct Obj *o);
extern void ISS_SYS_DeleteCity(u8 *p);
extern void ISS_SYS_DeleteDungeon(int a0);
extern void ISS_SYS_DeleteZone(int a0);
extern void ISS_SYS_DeleteSwitch(u8 *p);
extern void ISS_SYS_Delete3ds(int a0);

void ISS_SYS_DeleteSubsystems(u32 a)
{
    ISS_SYS_DeleteRoad((struct Obj *)a);
    ISS_SYS_DeleteCity((u8 *)a);
    ISS_SYS_DeleteDungeon(a);
    ISS_SYS_DeleteZone(a);
    ISS_SYS_DeleteSwitch((u8 *)a);
    ISS_SYS_Delete3ds(a);
}
