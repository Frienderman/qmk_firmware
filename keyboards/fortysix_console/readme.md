FortySix
========

![FortySix]()

The FortySix is a split 46-key column staggered keyboard with 3-key thumb clusters (2x 23 key boards) made by Frienderman it runs off a Sparkfun Pro micro using a 5*8 Matrix (4*5 for the main boards and 1*3 for the clusters). Each hand (lefty & righty) is run off an individual pro micro and can be layer switched individually.

- Keyboard maintainer: [Frienderman](http://github.com/frienderman)  
- Hardware supported:
    - FortySix V1.0  
- Hardware availability:  
    - Not current available.  

# Building the firmware

[Install the build tools.](https://docs.qmk.fm/getting_started_build_tools.html)

In the root directory of the repository, build the firmware with a command like (using lefty or righty as needed):

    make fortysix:<keymap>

    e.g. make fortysix:default_lefty would build the left hand default keymap.

For more information on the layout option and other ones, see the [`make` guide](https://docs.qmk.fm/getting_started_make_guide.html).
