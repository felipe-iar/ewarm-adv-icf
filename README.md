# Header-based module inclusion

:warning: EXPERIMENTAL

This is a simple demo on how to make the ILINK aware of which modules to include in a multi-slot app design, from the preprocessor perspective.

### `choices.h`
- In this auxiliary header, once `USE_X` is defined, a couple of marker sections (`.blk<?>_{start|end}`) are created.
https://github.com/felipe-iar/ewarm-adv-icf/blob/7cd9fc8c52418c7cd0d7e59084eb04e898844109/choices.h#L4-L11

### `app.icf`
- A block `ro_blk<?>_slot` is defined with `1k` either for _alignment_ and _growth_ (a.k.a. `end alignment`).
- It uses section wrappers (`.blk<?>_{start|end}` for the object `fun<?>.o`.
- If there is no `.blk<?>_{start|end}` section in the program, the entire block will not link.
https://github.com/felipe-iar/ewarm-adv-icf/blob/7cd9fc8c52418c7cd0d7e59084eb04e898844109/app.icf#L149-L155

### `main.c`
- From the application, now it is possible to refer to the block boundaries. Example using macros:
https://github.com/felipe-iar/ewarm-adv-icf/blob/7cd9fc8c52418c7cd0d7e59084eb04e898844109/main.c#L8-L11

One simple example:
https://github.com/felipe-iar/ewarm-adv-icf/blob/7cd9fc8c52418c7cd0d7e59084eb04e898844109/main.c#L16-L21

<details> <summary>Output example (click to unfold)</summary>

>```
>X block start address: 0x00002000
>X block final address: 0x000043ff
>X slot has 9 kbytes.
>...
>```

</details>





