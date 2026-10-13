/*
 * function: BTL_ID_IsGenesectDrive
 * address: 0x0689C990
 * packet: pkt_ov095_0689C990
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov095/unit_0689C888.c and filed here.
 *
 * symbols:
 *   gGenesectDriveItems 0x0689E2BC data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsGenesectDrive(unsigned a);
extern unsigned short gGenesectDriveItems[];

int BTL_ID_IsGenesectDrive(unsigned a)
{
    return BTL_ID_IsInList(a, gGenesectDriveItems, 4);
}
