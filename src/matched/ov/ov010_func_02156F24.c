/*
 * function: MUSICAL_STAGE_SYS_Main
 * address:  0x02156F24
 * packet:   pkt_ov010_02156F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACTING_Create  0x021F8480  thumb ov132
 *   STA_ACTING_Update  0x021F879C  thumb
 *   STA_ACTING_Delete  0x021F8640  thumb
 */

typedef unsigned char  u8;
extern u8 *STA_ACTING_Create(u8 *input, int heap);
extern int STA_ACTING_Update(int);
extern void STA_ACTING_Delete(int);

int MUSICAL_STAGE_SYS_Main(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)STA_ACTING_Create((u8 *)d[0], 0x2e);
        *state = 1;
        break;
    case 1:
        if (STA_ACTING_Update(d[1]) == 1)
            *state = 2;
        break;
    case 2:
        STA_ACTING_Delete(d[1]);
        return 1;
    }
    return 0;
}
