/*
 * unit: yes
 * function: GDS_RAP_UpdateSocketState, GDS_RAP_PollNothing
 * address: 0x021D6FB0
 * packet: pkt_ov125_021D6FB0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_SOCKET_GetState 0x021D85C0 arm ov125
 *   GDS_SOCKET_GetError 0x021D85DC arm ov125
 *   GDS_RAP_ReadReply 0x021D71D8 thumb ov125
 *   GDS_RAP_PollNothing 0x021D7060 thumb ov125
 *   GDS_RAP_PollNothingAfterError 0x021D7120 thumb ov125
 */
#include "../include/Obj00327.h"
extern unsigned int GDS_SOCKET_GetState(void);
extern int GDS_SOCKET_GetError(void);
extern int GDS_RAP_ReadReply(char *p);
extern int GDS_RAP_PollNothing(void);
extern int GDS_RAP_PollNothingAfterError(void);
int GDS_RAP_UpdateSocketState(char *p)
{
    unsigned int state;
    if (((struct Obj00327 *)p)->f3DC == 0x55f4) return 1;
    state = GDS_SOCKET_GetState();
    ((struct Obj00327 *)p)->f140 = state;
    if (state != ((struct Obj00327 *)p)->f144) {
        switch (state) {
        case 7:
            ((struct Obj00327 *)p)->f168 = 1;
            ((struct Obj00327 *)p)->f16C = 0;
            ((struct Obj00327 *)p)->f170 = 7;
            ((struct Obj00327 *)p)->f164 = 1;
            ((struct Obj00327 *)p)->f3FC = GDS_RAP_PollNothingAfterError;
            break;
        case 8:
            ((struct Obj00327 *)p)->f3FC = GDS_RAP_PollNothing;
            GDS_RAP_ReadReply(p);
            break;
        case 9:
            ((struct Obj00327 *)p)->f168 = 0;
            ((struct Obj00327 *)p)->f16C = 0;
            ((struct Obj00327 *)p)->f170 = GDS_SOCKET_GetError();
            ((struct Obj00327 *)p)->f164 = 1;
            ((struct Obj00327 *)p)->f3FC = GDS_RAP_PollNothingAfterError;
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        default: break;
        }
        ((struct Obj00327 *)p)->f144 = ((struct Obj00327 *)p)->f140;
    }
    return 1;
}
int GDS_RAP_PollNothing(void) { return 1; }
