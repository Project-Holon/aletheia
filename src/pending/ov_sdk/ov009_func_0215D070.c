/*
 * function: SOCL_CreateSocket
 * address:  0x0215d070
 * packet:   pkt_ov009_0215D070
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * u21: the defining object socl_create.o is .comment 4.0.0.1024 -> dsi/1.1p1. Every instruction
 *      matches except the flag select: the image emits the single predicated `movne r1, r5`,
 *      reusing the constant 1 still sitting in r5 from the command flag, while 1.1p1 emits
 *      `moveq r5, r1 / mov r1, r5` and so is 4 bytes long (184 vs 180). Twelve spellings (nested
 *      if, &&, ternary, `!= 0`, the bare masked value, long/unsigned flag, hoisted b) either keep
 *      the two-instruction select or collapse the block to 164/168 B. First divergence +005C
 *      image `movne r1, r5` | ours `moveq r5, r1`.
 * u1: eight more flag spellings (if/if, `&&` into flag=1, ternary, `(int)(ac&1)`, `!!`, an `ac` temp, `if (flag)`) - the `moveq r5,r1` / `mov r1,r5` select survives all of them; the `flag = 1` and `&&` forms collapse the block to 164 B. Residue is the image's predicated `movne r1, r5` (reusing the 1 already in r5).
 *
 * blocker:  codegen, 4 bytes long (184 vs 180).  Every instruction matches
 *           except the `flag` boolean at +0058: the original emits the
 *           single `movne r1, r5` (r5 already holds 1 for the command flag),
 *           while this source (`flag = (ac & 1) != 0`) makes the compiler
 *           emit `moveq r5, r1; mov r1, r5`.  The r5-held 1 is the only
 *           difference; tried `flag = 1` in nested and `&&` forms (both
 *           shrink to 164) and the ternary spelling (no change).
 *
 * sdk:      SOCL_CreateSocket (socl_create.o)
 *
 * symbols:
 *   SOCLi_StartupSocket                0x0215d198 arm
 *   SOCLi_CreateCommandPacket          0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInCtrlPipe  0x0215cfa8 arm
 *   SOCLiConfigPtr                     0x021a1cd8 data
 *   SOCLi_CreateSocketCallBack         0x0215d124 arm
 *   SOCLi_Resource                     0x021aa4ac data
 */

struct SOCLSocketParam;

struct SOCLSocket {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
};

struct SOCLiCommandPacket;

struct SOCLiResource {
    unsigned long count0;
    unsigned long count4;
};

extern void *SOCLiConfigPtr;
extern struct SOCLiResource SOCLi_Resource;
extern struct SOCLSocket *SOCLi_StartupSocket(struct SOCLSocketParam *param);
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket *socket,
                                                            long flag);
extern int SOCLi_ExecCommandPacketInCtrlPipe(struct SOCLSocket *socket,
                                             struct SOCLiCommandPacket *command);
extern int SOCLi_CreateSocketCallBack(void *arg);

int SOCL_CreateSocket(struct SOCLSocketParam *param)
{
    struct SOCLSocket *socket;
    struct SOCLiCommandPacket *command;

    if (SOCLiConfigPtr == 0)
        return -0x27;
    socket = SOCLi_StartupSocket(param);
    if (socket == 0)
        return -0x31;
    command = SOCLi_CreateCommandPacket(SOCLi_CreateSocketCallBack, socket, 1);
    SOCLi_ExecCommandPacketInCtrlPipe(socket, command);
    {
        int flag = 0;

        if (socket != 0)
            flag = (socket->field_ac & 1) != 0;
        if (flag != 0) {
            int b = (socket->field_af == 0 || socket->field_af == 4);

            if (b)
                SOCLi_Resource.count0++;
            else
                SOCLi_Resource.count4++;
        }
    }
    return (int)socket;
}
