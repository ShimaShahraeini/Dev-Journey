namespace GameStore.Api.Dtos;

public record class GameSummeryDto(
    int ID,
    string Name,
    string Genre,
    decimal Price,
    DateOnly ReleaseDate);
