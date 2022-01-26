#include <iostream>
#include <GLFW/glfw3.h>
#include <CT_Config.h>
#ifdef USE_ADDER
    #include <adder.h>
#endif

int main(int argc, char* argv[]){



    std::cout << "Hello, World !" << std::endl;
#ifdef USE_ADDER
    std::cout << "Using Adder library " << add(72.1, 73.8) << std::endl;
#else
    std::cout << "Not using Adder library " << 72.1f + 73.8 << '\n' << std::endl;
#endif
    std::cout << argv[0] << " Version " << CT_VERSION_MAJOR << "." << CT_VERSION_MINOR << "\n"; 

    GLFWwindow *window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

        // Main loop
    while( !glfwWindowShouldClose(window) )
    {

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program
    exit( EXIT_SUCCESS );

    return 0;
}