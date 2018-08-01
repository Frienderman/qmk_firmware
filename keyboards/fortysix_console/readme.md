FortySix Console
========

![FortySix]()
The FortySix Console is an add-on board for the FortySix, it adds a large grid of numpad and other control keys (esc, ctrl, del end along with other brackets and the arrow keys). The Console is a 38-key board or optionally 40 key if the RGB LEDs are not installed.
The FortySix is a split 46-key column staggered keyboard with 3-key thumb clusters (2x 23 key boards) made by Frienderman it runs off a Sparkfun Pro micro using a 5*8 Matrix (4*5 for the main boards and 1*3 for the clusters). Each hand (lefty & righty) is run off an individual pro micro and can be layer switched individually.

- Keyboard maintainer: [Frienderman](http://github.com/frienderman)  
- Hardware supported:
    - FortySix Console V1.0  
- Hardware availability:  
    - Not current available.  

# Building the firmware

[Install the build tools.](https://docs.qmk.fm/getting_started_build_tools.html)

In the root directory of the repository, build the firmware with a command like (using lefty or righty as needed):

    make fortysix_console:<keymap>

    e.g. make fortysix_console:default would build the console default keymap.

For more information on the layout option and other ones, see the [`make` guide](https://docs.qmk.fm/getting_started_make_guide.html).
