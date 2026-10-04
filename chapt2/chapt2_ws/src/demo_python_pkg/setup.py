from setuptools import find_packages, setup

package_name = 'demo_python_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='at',
    maintainer_email='at@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'python_node = demo_python_pkg.python_node:main' ,#添加功能包
            'person_node = demo_python_pkg.person_node:main' ,#添加功能包
            'writer_node = demo_python_pkg.writer_node:main' ,#添加功能包

        ],
    },
)


