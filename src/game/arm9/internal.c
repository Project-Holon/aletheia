/*
 * file:     internal.c
 * unit:     yes
 * function: RTCi_ReadRawDateTimeAsync, RTCi_ReadRawDateAsync, RTCi_ReadRawTimeAsync, RTCi_WriteRawStatus2Async, RtcSendPxiCommand
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

typedef int BOOL;

extern int RtcSendPxiCommand(unsigned long command);
int PXI_SendWordByFifo(int fifotag, unsigned long data, BOOL err);
int RTCi_ReadRawDateTimeAsync(void);
int RTCi_ReadRawDateAsync(void);
int RTCi_ReadRawTimeAsync(void);
int RTCi_WriteRawStatus2Async(void);
BOOL RtcSendPxiCommand(unsigned long command);

int RTCi_ReadRawDateTimeAsync(void)
{
    return RtcSendPxiCommand(0x10);
}

int RTCi_ReadRawDateAsync(void)
{
    return RtcSendPxiCommand(0x11);
}

int RTCi_ReadRawTimeAsync(void)
{
    return RtcSendPxiCommand(0x12);
}


int RTCi_WriteRawStatus2Async(void)
{
    return RtcSendPxiCommand(0x27);
}


/*
 * sdk:      RtcSendPxiCommand (librtc.TWL.HYB.a internal.o)
 */
BOOL RtcSendPxiCommand(unsigned long command)
{
    command = (command << 8) & 0x7F00;
    if (PXI_SendWordByFifo(5, command, 0) < 0) {
        return 0;
    }
    return 1;
}
