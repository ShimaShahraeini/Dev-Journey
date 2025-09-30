using System;
using GameStore.Api.Dtos;
using GameStore.Api.Entities;

namespace GameStore.Api.Mapping;

public static class GameMapping
{
    public static Game ToEntity(this CreateGameDto game)
    {
        return new Game()
        {
            Name = game.Name,
            GenreID = game.GenreId,
            Price = game.Price,
            ReleaseDate = game.ReleaseDate
        };
    }

    public static Game ToEntity(this UpdateGameDto game, int id)
    {
        return new Game()
        {
            ID = id,
            Name = game.Name,
            GenreID = game.GenreId,
            Price = game.Price,
            ReleaseDate = game.ReleaseDate
        };
    }

    public static GameSummeryDto ToGameSummeryDto(this Game game)
    {
        return new GameSummeryDto( 
            game.ID,
            game.Name,
            game.Genre!.Name,
            game.Price,
            game.ReleaseDate
        );
    }

    public static GameDetailsDto ToGameDetailsDto(this Game game)
    {
        return new GameDetailsDto( 
            game.ID,
            game.Name,
            game.GenreID,
            game.Price,
            game.ReleaseDate
        );
    }
}
