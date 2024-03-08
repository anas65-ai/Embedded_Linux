# Yocto



-----------------------------------------------------------------------------------------------------------------------------------------------------------

## Table of content





-----------------------------------------------------------------------------------------------------------------------------------------------------------

# 1. Create Layers

To remember what is the Yocto Layers Read This [Part](https://github.com/anaskhamees/Embedded_Linux/tree/main/EmbeddedLinuxTasks/10.Yocto/10.1.Yocto_Introduction#3-yocto-terminologies) , But for create a layer follow the following steps:

```bash
bitbake-layers create-layer <path/to/meta-layername>
```

- Go to `poky` directory and source the script:

  ```bash
  source oe-init-build-env
  ```

  ![image-20240309001126783](README.assets/image-20240309001126783.png)

- In my case I created Layer in `/home/anas/yocto/poky` , Called `AnasLayer`

```
bitbake-layers create-layer /home/anas/yocto/poky/meta-AnasLayer
```

>Note that you must start the Layer name by **meta-**

![image-20240309001203211](README.assets/image-20240309001203211.png)

![image-20240309001450986](README.assets/image-20240309001450986.png)

![image-20240309001529841](README.assets/image-20240309001529841.png)

Poky Created a reference of an example recipe in your layer and `layer.conf` file is created also.

![image-20240309001706674](README.assets/image-20240309001706674.png)

- Add Your Layer in Poky

  ```bash
  bitbake-layers add-layer <path/to/meta-layername>
  ```

  ```bash
  bitbake-layers add-layer /home/anas/yocto/poky/meta-AnasLayer
  ```

- Make sure that the Layer Created 

  ```
  bitbake-layers show-layers
  ```

  ![image-20240309001817923](README.assets/image-20240309001817923.png)

Also, go to `/home/anas/yocto/poky/build/conf` and open **bblayers.config** to see your new Layer.

![](README.assets/BBLAYERS.drawio.svg)

## 2. Create Recipe

After you create a Layer, Poky will create a example of **Recipe** Automatically, you can use it or create your own recipes. But you should create your recipes into `recipes-example` directory, because **Bitbake** will search for recipes in directories start with `recipes-` 

![](README.assets/BBLAYERS.drawio(1).svg)

- Create Directory with any name in `recipes-example` 

  ![image-20240309004007644](README.assets/image-20240309004007644.png)

- Create a recipe file `.bb` 

  