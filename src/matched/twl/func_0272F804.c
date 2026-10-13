/*
 * function: MIi_GetControlData
 * address:  0x0272F804
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

u32 MIi_GetControlData(u32 type)
{
    switch (type) {
    case 0:
        return 0x6000;
    case 1:
        return 0;
    case 2:
    case 8:
        return 0x800;
    case 9:
        return 0x40000800;
    case 3:
        return 0x4000;
    case 4:
        return 0x4800;
    case 10:
        return 0x60005000;
    case 5:
        return 0x20001000;
    case 6:
        return 0x60001000;
    case 7:
        return 0x20000800;
    default:
        return 0;
    }
}
