# Software for carritoAP

![](https://github.com/levacarrillo/carritoAP/blob/master/carritoAP.PNG)

###Use the branch master to work with Ubuntu desktop:
```
 git checkout master
```
###If you want to compile it in raspberry change to raspberry:
```
 git checkout raspberry
```
### Compilation
```
 cd ~/carritoAP/catkin_ws
 catkin_make
 source ~/carritoAP/catkin_ws/devel/setup.bash
```

### Testing
```
 roslaunch surge_et_ambula carritoAP.launch 
 roslaunch surge_et_ambula carritoAP_simul.launch 
```
