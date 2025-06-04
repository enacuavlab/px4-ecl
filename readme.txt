cd ~/Tmp
git clone https://github.com/PX4/PX4-Autopilot.git
(491.46 Mio)
cd PX4-Autopilot/
git checkout v1.15.4

~/Tmp
git clone git@github.com:enacuavlab/px4-ecl.git
(470.63 Kio)

----------------------------------------------
cd px4-ecl
ln -s ../PX4-Autopilot/src/modules/ekf2/EKF
ln -s ../PX4-Autopilot/src/lib/geo 
ln -s ../PX4-Autopilot/src/lib/world_magnetic_model 
ln -s ../PX4-Autopilot/src/lib/mathlib
ln -s ../PX4-Autopilot/src/lib/matrix/matrix
ln -s ../PX4-Autopilot/src/lib/atmosphere 
ln -s ../PX4-Autopilot/src/modules/ekf2/EKF/python/ekf_derivation
ln -s ../PX4-Autopilot/platforms/common/include/px4_platform_common
ln -s ../PX4-Autopilot/Tools
ln -s ../PX4-Autopilot/msg

pip install empy==3.3.4

----------------------------------------------
git clone git@github.com:enacuavlab/paparazzi.git
(132.80 Mio)
cd paparazzi
git checkout opticflow_MTF01 
make

cp conf/airframes/ENAC/conf_enac_vto.xml conf/conf.xml

ln -s ~/Project/paparazzi/sw/ext/ecl  ~/Tmp/px4-ecl

export PAPARAZZI_SRC=/home/pprz/Projects/paparazzi
export PAPARAZZI_HOME=/home/pprz/Projects/paparazzi
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 clean_ac
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 ap.compile
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 ap.upload

----------------------------------------------
cd ~/Tmp/PX4-Autopilot
git diff > ../px4-ecl/my_custom_patch_file.patch
git apply ../px4-ecl/my_custom_patch_file.patch

----------------------------------------------
keep compiling modifying :
- sw/airborne/modules/ins/ins_ekf2.cpp
- conf/modules/ins_ekf2.xml

TODO

/home/pprz/Projects/paparazzi/sw/ext/ecl/ekf_derivation/generated/state.h:36:25: warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
   36 |                 return *reinterpret_cast<matrix::Vector<float, 24>*>(const_cast<float*>(reinterpret_cast<const float*>(&quat_nominal)));
