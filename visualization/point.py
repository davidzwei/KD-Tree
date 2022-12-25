from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import random




def plot_img(node):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    x = []
    y = []
    z = []

    for i in range(node):
        x.append(random.randint(1, node))

    for i in range(node):
        y.append(random.randint(1, node))

    for i in range(node):
        z.append(random.randint(1, node))

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    ax.scatter(x, y, z, c='r', marker='o')

    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')

    img_name = "dim_3_node_" + str(node) + ".png"
    # print(img_name

    plt.savefig(img_name)

def plot_dim2(node):
    fig = plt.figure()
    x = []
    y = []
    for i in range(node):
        x.append(random.randint(1, node))

    for i in range(node):
        y.append(random.randint(1, node))

    plt.scatter(x, y)
    # plt.show()
    img_name = "dim_2_node_" + str(node) + ".png"
    # print(img_name)

    plt.savefig(img_name)



plot_img(10)
plot_img(100)
plot_img(1000)

plot_dim2(10)
plot_dim2(100)
plot_dim2(1000)



