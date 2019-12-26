# PrecisionCheck

Toy project to use the lib (boost_matheval|https://github.com/hmenke/boost_matheval)

To compile in my machine, I changed the boost version.

```ps
> cmake -G "Visual Studio 16 2019" ../src
```

# Plataform error
If runnig you get a error for missing dlls
Check the path to 
* Qt5Core.dll                                                           
* Qt5Cored.dll                                                          
* Qt5Gui.dll                                                            
* Qt5Guid.dll                                                           
* Qt5Widgets.dll                                                        
* Qt5Widgetsd.dll 
* platforms\qwindows.dll
* platforms\qwindowsd.dll