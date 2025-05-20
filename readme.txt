cd ~/Tmp
git clone https://github.com/PX4/PX4-Autopilot.git
cd PX4-Autopilot/
git checkout v1.15.4

~/Tmp
git clone git@github.com:enacuavlab/px4-ecl.git

----------------------------------------------
cd px4-ecl
ln -s /home/pprz/Tmp/PX4-Autopilot/src/modules/ekf2/EKF
ln -s /home/pprz/Tmp/PX4-Autopilot/src/lib/geo 
ln -s /home/pprz/Tmp/PX4-Autopilot/src/lib/world_magnetic_model 
ln -s /home/pprz/Tmp/PX4-Autopilot/src/lib/mathlib
ln -s /home/pprz/Tmp/PX4-Autopilot/src/lib/matrix/matrix
ln -s /home/pprz/Tmp/PX4-Autopilot/src/lib/atmosphere 

ln -s /home/pprz/Tmp/PX4-Autopilot/src/modules/ekf2/EKF/python/ekf_derivation

ln -s /home/pprz/Tmp/PX4-Autopilot/platforms/common/include/px4_platform_common

----------------------------------------------
ln -s ~/Project/paparazzi/sw/ext/ecl  ~/Tmp/px4-ecl

export PAPARAZZI_SRC=/home/pprz/Projects/paparazzi
export PAPARAZZI_HOME=/home/pprz/Projects/paparazzi
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 clean_ac
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 ap.compile

----------------------------------------------
git diff > my_custom_patch_file.patch
git apply patch_file.patch

----------------------------------------------
lrwxrwxrwx 1 pprz pprz   47 mai   20 14:43 atmosphere -> /home/pprz/Tmp/PX4-Autopilot/src/lib/atmosphere
lrwxrwxrwx 1 pprz pprz   49 mai   20 13:32 EKF -> /home/pprz/Tmp/PX4-Autopilot/src/modules/ekf2/EKF
lrwxrwxrwx 1 pprz pprz   72 mai   20 14:45 ekf_derivation -> /home/pprz/Tmp/PX4-Autopilot/src/modules/ekf2/EKF/python/ekf_derivation/
lrwxrwxrwx 1 pprz pprz   40 mai   20 14:16 geo -> /home/pprz/Tmp/PX4-Autopilot/src/lib/geo
drwxrwxr-x 8 pprz pprz 4096 mai   20 14:52 .git
lrwxrwxrwx 1 pprz pprz   44 mai   20 14:19 mathlib -> /home/pprz/Tmp/PX4-Autopilot/src/lib/mathlib
lrwxrwxrwx 1 pprz pprz   51 mai   20 14:41 matrix -> /home/pprz/Tmp/PX4-Autopilot/src/lib/matrix/matrix/
-rw-rw-r-- 1 pprz pprz 2304 mai   20 14:50 my_custom_patch_file.patch
lrwxrwxrwx 1 pprz pprz   73 mai   20 14:05 px4_platform_common -> /home/pprz/Tmp/PX4-Autopilot/platforms/common/include/px4_platform_common
-rw-rw-r-- 1 pprz pprz 1377 mai   20 14:51 readme.txt
lrwxrwxrwx 1 pprz pprz   57 mai   20 14:18 world_magnetic_model -> /home/pprz/Tmp/PX4-Autopilot/src/lib/world_magnetic_model

----------------------------------------------
TODO 
/home/pprz/Projects/paparazzi/sw/ext/ecl/EKF/ekf.h:58:10: fatal error: uORB/topics/estimator_aid_source1d.h: No such file or directory
