#include <iostream>
#include "Movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    /*
    // bool found = false;
    // for (size_t i = 0; i < movies.size(); i++)
    // {
    //     if (movies[i].get_name() == name)
    //     {
    //         found = true;
    //     }
    // }
    // if (!found)
    // {
    //     movies.push_back(Movie(name, rating, watched));
    // }
    // return !found;
    */

    for (const Movie &movie : movies)
    {
        if (movie.get_name() == name)
        {
            return false;
        }
    }

    Movie temp{name, rating, watched};
    movies.push_back(temp);

    return true;
}

bool Movies::increment_watched(std::string name)
{
    /*
    // int idx = -1;
    // for (size_t i = 0; i < movies.size(); i++)
    // {
    //     if (movies[i].get_name() == name)
    //     {
    //         idx = i;
    //     }
    // }

    // if (idx != -1)
    // {
    //     movies[idx].set_watched(movies[idx].get_watched() + 1);
    // }

    // return idx != -1;
    */

    for (Movie &movie : movies)
    {
        if (movie.get_name() == name)
        {
            movie.increment_watched();
            return true;
        }
    }

    return false;
}

void Movies::display() const
{
    if (movies.size() == 0)
    {
        std::cout << "Sorry, no movies to display\n"
                  << std::endl;
    }
    else
    {
        std::cout << "\n====================================" << std::endl;
        // for (size_t i = 0; i < movies.size(); i++)
        for (const auto &movie : movies)
        {
            movie.display();
        }
        std::cout << "\n====================================" << std::endl;
    }
}