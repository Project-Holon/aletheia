/*
 * file:     unit_02088EEC.c
 * unit:     yes
 * function: func_02088EEC, func_02088EFC, func_02088F0C, func_02088F1C, func_02088F2C
 * address:  0x02088EEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   RtcSendPxiCommand  0x02088F2C  arm
 *   PXI_SendWordByFifo             0x02088610  arm
 */
typedef unsigned int   u32_0;

typedef unsigned int   u32_1;

typedef unsigned int   u32_2;

typedef unsigned long u32_02088F2C;

typedef int BOOL;

extern int RtcSendPxiCommand(unsigned long command);
int PXI_SendWordByFifo(int fifotag, u32_02088F2C data, BOOL err);
asm void RTCi_ReadRawDateTimeAsync(void);
asm void RTCi_ReadRawDateAsync(void);
asm void RTCi_ReadRawTimeAsync(void);
int RTCi_WriteRawStatus2Async(void);
BOOL func_02088F2C(u32_02088F2C command);

asm void RTCi_ReadRawDateTimeAsync(void)
{
    ldr ip, =func_02088F2C
    mov r0, #0x10
    bx ip
}

asm void RTCi_ReadRawDateAsync(void)
{
    ldr ip, =func_02088F2C
    mov r0, #0x11
    bx ip
}

asm void RTCi_ReadRawTimeAsync(void)
{
    ldr ip, =func_02088F2C
    mov r0, #0x12
    bx ip
}


int RTCi_WriteRawStatus2Async(void)
{
    return RtcSendPxiCommand(0x27);
}


/*
 * sdk:      RtcSendPxiCommand (librtc.TWL.HYB.a internal.o)
 */
BOOL func_02088F2C(u32_02088F2C command)
{
    command = (command << 8) & 0x7F00;
    if (PXI_SendWordByFifo(5, command, 0) < 0) {
        return 0;
    }
    return 1;
}
