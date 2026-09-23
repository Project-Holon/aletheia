# Wave 17 lane 17K: TWL autoload region (stopped: arm9i is modcrypted)

Nothing was added. Every tool, layout and listing change was reverted; match.py selftest is still 167 of 167, the region count stays 242 of 242, and the worklist figures and ARM9 denominator are unchanged. func_0206DC00 stays MATCH in src/pending.

## Finding

arm9i.bin is not plain BLZ. It is modcrypted:

- header 0x1C = 0x4003 (bit 1: modcrypt enabled)
- modcrypt area 1 (header 0x220/0x224) is ROM 0x0C403000 + 0x4000, and header 0x1C0 puts the start of arm9i at ROM 0x0C403000. So the first 0x4000 bytes of arm9i.bin are AES-CTR ciphertext.

blz.decompress still gives the expected 0x12F24 -> 0x32DB4 bytes, and the TWL autoload table at the end is readable (0x02700000, code 0x32DA0, bss 0x2DA0, static init 0x0272E9D4). The front of the output is not. With the first 0x4000 input bytes set to 0xFF, the output differs up to arm9i offset 0x7090 (ram 0x02407090). Filled with zeros, the stream is exhausted. So about the first 0x708C bytes of the `twl` payload (0x02700000..~0x0270708C) come from ciphertext. A trial listing confirmed this: that area traces as nonsense Thumb (for example func_027000C8), but it still reassembled. Byte-identical reassembly of those bytes would prove nothing.

The two func_0206DC00 targets are in the clean part. In the trial listing both traced as ARM function starts (func_0272FEF4 and func_027300F0, push prologues). So the plan works once arm9i is decrypted.

## To proceed

extract (ndsrom.py) needs a modcrypt decrypt step for area 1: AES-CTR, with the key from the retail modcrypt scheme (KeyX from "Nintendo" plus the game code, KeyY from the ARM9i hash in the TWL header). After that, the delink/disasm/build/match changes can be reapplied. The trial implementation was about 150 lines across the four tools.
